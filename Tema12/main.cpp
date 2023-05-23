#include <iostream>
#include<vector>
#include<algorithm>

enum class TipContact {
    PRIETEN,
    CUNOSCUT,
    COLEG
};

///clasa Contact
class Contact {
protected:
    std::string name;

public:
    Contact(const std::string& name) : name(name) {}

    std::string getName() {
        return name;
    }

    virtual TipContact getTipContact() = 0;

};

///clasa Prieten derivata din clasa Contact
class Prieten : public Contact {
    std::string birthDate;
    std::string Phone;
    std::string Addres;

public:
    Prieten(const std::string& name, const std::string& birthDate, const std::string& Phone, const std::string& Addres)
        : Contact(name), birthDate(birthDate), Phone(Phone), Addres(Addres) {}

    TipContact getTipContact(){
        return TipContact::PRIETEN;
    }
};

///clasa Cunoscut derivata din clasa Contact
class Cunoscut : public Contact {

    std::string Phone;
public:
    Cunoscut(const std::string &name, const std::string &Phone): Contact(name), Phone(Phone){}

    TipContact getTipContact() {
        return TipContact::CUNOSCUT;
    }
};

///clasa Coleg derivata din clasa Contact
class Coleg : public Contact {
    std::string Phone;
    std::string company;
    std::string Addres;

public:
    Coleg(const std::string &name,const std::string &Phone, const std::string &company, const std::string &Addres)
        : Contact(name), Phone(Phone),company(company), Addres(Addres) {}
    TipContact getTipContact() {
        return TipContact::COLEG;
    }
};

///clasa Agenda
class Agenda {
private:
    std::vector<Contact*> contacts;
public:
    void adaugaContact(Contact* contact) {
        contacts.push_back(contact);
    }

    Contact* cautaContact(const std::string& nume){
        auto it = std::find_if(contacts.begin(), contacts.end(), [&nume](Contact* contact) {
            return contact->getName() == nume;
            });

        if (it != contacts.end()) {
            return *it;
        }

        return nullptr;
    }
    std::vector<Prieten*> getListaPrieteni() {
        std::vector<Prieten*> prieteni;

        for (Contact* contact : contacts) {
            if (contact->getTipContact() == TipContact::PRIETEN) {
                prieteni.push_back(static_cast<Prieten*>(contact));
            }
        }

        return prieteni;
    }

    void stergeContact(const std::string& nume) {
        auto it = std::find_if(contacts.begin(), contacts.end(), [&nume](Contact* contact) {
            return contact->getName() == nume;
            });

        if (it != contacts.end()) {
            delete* it;
            contacts.erase(it);
        }
    }

    std::vector<Contact*> getContacte() {
        return contacts;
    }

    ~Agenda() {
        for (Contact* contact : contacts) {
            delete contact;
        }
    }

};
int main() {
    // Crearea unei instanțe de agendă
    Agenda agenda;

    // Adăugarea unor contacte în agendă
    agenda.adaugaContact(new Prieten("Ion", "01/01/1990", "123456789", "Strada X"));
    agenda.adaugaContact(new Cunoscut("Maria", "987654321"));
    agenda.adaugaContact(new Coleg("George", "555555555", "Firma Y", "Strada Z"));

    // Căutarea unui contact după nume
    Contact* contactCautat = agenda.cautaContact("Ion");
    if (contactCautat) {
        std::cout << "Contactul cautat: " << contactCautat->getName() << std::endl;
    }
    else {
        std::cout << "Contactul cautat nu exista in agenda." << std::endl;
    }

    // Obținerea unei liste de prieteni
    std::vector<Prieten*> listaPrieteni = agenda.getListaPrieteni();
    std::cout << "Lista prieteni:" << std::endl;
    for (Prieten* prieten : listaPrieteni) {
        std::cout << "- " << prieten->getName() << std::endl;
    }

    // Ștergerea unui contact
    agenda.stergeContact("Maria");

    // Afisarea tuturor contactelor ramase in agenda
    std::cout << "Contacte ramase in agenda:" << std::endl;
    for (Contact* contact : agenda.getContacte()) {
        std::cout << "- " << contact->getName() << std::endl;
    }

    
    return 0;
}


