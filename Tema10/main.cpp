#include <iostream>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS

class IndexOut {
	const char* what() const throw() {
		return "IndexOut";
	}
};

class Compare
{
public:
	virtual int CompareElements(const void* e1,const void* e2) = 0;
};


template<class T>
class ArrayIterator
{
private:
	T** List;
	int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:

	ArrayIterator() : Current(0),List(nullptr){}
	ArrayIterator(T** list, int current) : List(list), Current(current) {}
	ArrayIterator& operator ++ () {
	
		Current++;
		return *this;
	
	}
	ArrayIterator& operator -- () {
		Current--;
		return *this;
	}
	bool operator= (ArrayIterator<T> &lista) {
		return Current == lista.Current;
	}
	bool operator!=(ArrayIterator<T>&lista) {
		return Current != lista.Current;
	}
	T* operator *() 
	{
		return List[Current];
	}
	
};

template<class T>
class Array
{
private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:

	Array() :List(nullptr), Capacity(0), Size(0) {} // Lista nu e alocata, Capacity si Size = 0
	~Array() {
		for (int i = 0; i < Size; ++i) {
			delete List[i];
		}
		delete[] List;
	}
	Array(int capacity) : Capacity(capacity), Size(0) {
		List = new T*[capacity];
		for (int i = 0; i < capacity; ++i) {
			List[i] = nullptr;
		}
	}
	Array(const Array<T>& otherArray) // constructor de copiere
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = new T * [Capacity];
		for (int i = 0; i < Size; ++i) {
			List[i] = new T(*otherArray.List[i]);
		}
		for (int i = Size; i < Capacity; ++i) {
			List[i] = nullptr;
		}
	}
	
	
	T& operator[] (int index) {
	
		if (index < 0 || index >= Size) {
			throw IndexOut();
		}
		return *(List[index]);
	}// arunca exceptie daca index este out of range

	const Array<T>& Insert(int index, const T& newElem) {
	
		if (index < 0 || index > Size) {
			throw IndexOut();
		}
		if (Size == Capacity) {
			int newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
			T** newList = new T * [newCapacity];
			for (int i = 0; i < Size; ++i) {
				newList[i] = List[i];
			}
			if (List) {
				delete[] List;
			}
			List = newList;
			Capacity = newCapacity;
		}
		
		for (int i = Size; i > index; i--) {
			List[i] = List[i - 1];
		}
		List[index] = new T(newElem);
		Size++;
		return *this;
	
	}// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	
	const Array<T>& operator+=(const T& newElem) {

		Insert(Size, newElem);
		return *this;
	}
	// adauga un element de tipul T la sfarsitul listei si returneaza this

	
	const Array<T>& Insert(int index, const Array<T> otherArray) {
	
		if (index < 0 || index >= Size) {
			throw IndexOut();
		}
	
		if (Size + otherArray.Size > Capacity) {
			T** newList = new T * [Capacity * 2];
			for (int i = 0; i < Size; i++) {
				newList[i] = List[i];
			}
			delete[] List;
			List = newList;
			Capacity *= 2;
		}

		for (int i = Size - 1; i >= index; i--) {
			List[i + otherArray.Size] = List[i];
		}

		for (int i = 0; i < otherArray.Size; i++) {
			List[index + i] = new T(otherArray.List[i]);
		}

		Size += otherArray.Size;

		return *this;
	
	} // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	
	
	const Array<T>& Delete(int index) {
	
		if (index < 0 || index >= Size) {
			throw IndexOut();
		}
		for (int i = index; i < Size; ++i) {
			List[i] = List[i + 1];
		}
		Size--;
	
	}// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	bool operator=(const Array<T>& otherArray) {
		if (List.Size != otherArray.Size) {
			return false;
		}
		for (int i = 0; i < Size; ++i) {
			if (List[i] != otherArray[i])
				return false;
		}
		return true;
	}

	void Sort() {
	
		for (int i = 0; i < Size - 1; i++) {
			for (int j = i+1; j < Size; j++) {
				if (*List[i] > *List[j]) {
					std::swap(List[i], List[j]);
				}
			}
		}
	} // sorteaza folosind comparatia intre elementele din T
	
	void Sort(Compare* comparator) {
	
		std::sort(List, List + Size, *comparator);
	
	}// sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) {
		int start = 0;
		int end = Size - 1;
		int mid = (start + end) / 2;

		while (start <= end) {
			if (*List[mid] == elem) {
				return mid;
			}
			else if (*List[mid] < elem) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
			mid = (start + end) / 2;
		}

		return -1;
	}// cauta un element folosind binary search in Array
	
	
	int BinarySearch(const T& elem, Compare* comparator) {
	
		int start = 0;
		int end = Size - 1;
		int mid = (start + end) / 2;

		while (start <= end) {
			if (comparator->CompareElements(List[mid], &elem) == 0) {
				return mid;
			}
			else if (comparator->CompareElements(List[mid], &elem) < 0) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
			mid = (start + end) / 2;
		}

		return -1;
	
	}//  cauta un element folosind binary search si un comparator

	int Find(const T& elem)
	{
		for (int i = 0; i < Size; i++) {
			if (*List[i] == elem) {
				return i;
			}
		}
		return -1;

	}// cauta un element in Array
	int Find(const T& elem, Compare* comparator)//  cauta un element folosind un comparator
	{
		for (int i = 0; i < Size; i++) {
			if (comparator->CompareElements(&elem, List[i]) == 0) {
				return i;
			}
		}
		return -1;
	}
	int GetSize() {
		return Size;
	}
	int GetCapacity() {
		return Capacity;
	}

	ArrayIterator<T> begin() {
		return ArrayIterator<T>(List, 0);
	}
	ArrayIterator<T> end() {
		return ArrayIterator<T>(List, Size);
	}

};

class Comparator2: public Compare {
	int CompareElements(const void* e1, const void* e2) {

		int* c1 = (int*)e1;
		int* c2 = (int*)e2;

		if (*c1 > *c2) return 1;
		else if (*c2 > *c1) return -1;
		return 0;
	}
};

int main()
{
	Comparator2 comp;
	Array<int> myArray(5);
	myArray.Insert(0,3);
	myArray.Insert(1,1);
	myArray.Insert(2,4);
	myArray.Insert(3,2);
	myArray.Insert(4,5);
	myArray.Sort();
	std::cout<<myArray.BinarySearch(3)<<std::endl;
	std::cout << myArray.Find(4, &comp)<<std::endl;
	myArray += -1;
	for (int* x:myArray) {
		std::cout << *x << ' ';
	}
}