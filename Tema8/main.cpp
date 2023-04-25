#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<fstream>

/// compare pentru coada
struct Compare {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

//functie transformare litere mari in litere mici
void lower_word(std::string& str) {

    for (char& c : str) {
        if(c>='A'&&c<='Z')
        c = tolower(c);
    }
}

//functie separare cuvinte
void sep_word(const std::string& str, std::vector<std::string>& words) {
    int start = 0;
    int final = str.find_first_of(" ,.!?"); // separatori
    while (final != std::string::npos) {
        std::string word = str.substr(start, final - start);
        if (!word.empty()) {
            words.push_back(word);
        }
        start = final + 1;
        final = str.find_first_of(" ,.!?", start);
    }
    std::string last_word = str.substr(start);///ultimul cuvant
    if (!last_word.empty()) {
        words.push_back(last_word);
    }
}

int main()
{
    std::ifstream file("input.txt");
    //caz in care nu merge fisierul
    if (!file.is_open()) {
        printf("Eroare la fisier");
        return -1;
    }

    std::string s;
    std::getline(file, s);//ia doar prima linie

    std::vector<std::string> cuvinte;
    //am pus in cuvinte(un vector de stringuri) in 
    sep_word(s, cuvinte);
    
    //am facut mapul
    std::map<std::string, int> wordCounts;
    for (auto it : cuvinte) {
        lower_word(it);
        wordCounts[it]++;
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> cuvQueue;
    for (const auto& pair : wordCounts) {
        cuvQueue.push(pair);
    }

    while (!cuvQueue.empty()) {
        auto pair = cuvQueue.top();
        std::cout << pair.first << " => " << pair.second << std::endl;
        cuvQueue.pop();
    }

    return 0;
}
