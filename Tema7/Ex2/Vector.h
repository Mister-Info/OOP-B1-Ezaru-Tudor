#pragma once
#include <iostream>
#include<cstdlib>
#define _CRT_SECURE_NO_WARNINGS
template<typename T>
class Vector {

	int capacity;
	int size;
	T* v;

public:
	Vector() : capacity(1), size(0), v(new T[capacity]) {}

	~Vector() {
		delete[] v;
	}

	static int compare(T x, T y) {
		if (x < y)
			return -1;
		if (y < x)
			return 1;
		return 0;
	}
	void sort(int(*comparare)(T, T)=compare) {
		for (int i = 0; i < size - 1; ++i) {
			for (int j = i + 1; j < size; ++j) {
				if (comparare(v[i], v[j]) == 1) {
					std::swap(v[i], v[j]);
				}
			}
		}
	}
	
	void insert(int index, T value) {
		if (index<0 || index>size) {
			printf("Eroare la insert");
			return;
		}
		if (size == capacity) {
			capacity *= 2;
			T* v2 = new T [capacity];
			for (int i = 0; i < size; i++) {
				v2[i] = v[i];
			}
			delete[] v;
			v = v2;
		}
		
		for (int i = size; i > index; i--) {
			v[i] = v[i-1];
		}
		v[index] = value;
		size++;
	}

	void remove(int index) {
		if (index<0 || index>size) {
			printf("Eroare la remove");
			return;
		}
		for (int i = index; i < size - 1; i++) {
			v[i] = v[i + 1];
		}
		size--;
	}

	void print() {

		for (int i = 0; i < size; ++i) {
			std::cout << v[i] << ' ';
		}
		printf("\n");
	}

};