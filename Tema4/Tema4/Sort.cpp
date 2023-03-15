#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "Sort.h"
#include<cstdio>
#include<stdarg.h>
#include<cstring>
#include<algorithm>
#include<iostream>

#include<cmath>


Sort::Sort(int count, int minim, int maxim) : count(count) {
	
	vector = new int[count];
	for (int i = 0; i < count; ++i) {
		int x = rand()%(maxim-minim)+minim;
		vector[i] = x;
	}
}

Sort::Sort(std::initializer_list<int>l) {
	count = l.size();
	vector = new int[count];
	int i = 0;
	for (int x : l) {
		vector[i++] = x;
	}
}

Sort::Sort(int* vector, int count) : vector(vector), count(count) {
	this->vector = new int[count];
	for (int i = 0; i < count; ++i) {
		this->vector[i] = vector[i];
	}
 }

Sort::Sort(int count, ...) : count(count) {
	vector = new int[count];
	va_list agrptr;
	va_start(agrptr, count);
	for (int i = 0; i < count; ++i) {
		int n = va_arg(agrptr, int);
		vector[i] = n;
	}
	va_end(agrptr);
}

Sort::Sort(const char* s) {
	int index = 0;
	int crt = 0;
	count = 0;
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == ',')
			count++;
	}
	count++;
	vector = new int[count];
	for (int i = 0; i < strlen(s); ++i) {
		int num=0;
		if (s[i] == ',') {
			for (index; index < i; index++) {
				num = num * 10 + (s[i] - '0');
			}
			vector[crt++] = num;
			num = 0;
			index++;
		}
	}
}

void Sort::InsertSort(bool ascendent) {
	
	if (!ascendent) {
		for (int i = 1; i < count; ++i) {
			int key = vector[i];
			int j = i - 1;
			while (key > vector[j] && j >= 0) {
				vector[j + 1] = vector[j];
				--j;
			}
			vector[j + 1] = key;
		}
	}
	else {
		for (int i = 1; i < count; ++i) {
			int key = vector[i];
			int j = i - 1;
			while (key < vector[j] && j >= 0) {
				vector[j + 1] = vector[j];
				--j;
			}
			vector[j + 1] = key;
		}
	}
}

void Sort::BubbleSort(bool ascendent) {
	
	if (!ascendent) {
		bool sorted;
		do {
			sorted = true;
			for (int i = 0; i < count - 1; ++i) {
				if (vector[i] < vector[i + 1])
				{
					int aux = vector[i];
					vector[i] = vector[i + 1];
					vector[i + 1] = aux;
					sorted = false;
				}
			}
		} while (!sorted);
	}

	else {
		bool sorted;
		do {
			sorted = true;
			for (int i = 0; i < count - 1; ++i) {
				if (vector[i] > vector[i + 1])
				{
					int aux = vector[i];
					vector[i] = vector[i + 1];
					vector[i + 1] = aux;
					sorted = false;
				}
			}
		} while (!sorted);
	}
}

int Sort::partition(int start, int end, bool ascending) {
	
		
	int x = vector[start]; // pivot
	int i = start;
	int j = end;
	while (true) {
		//ignore all the numbers greater than X to left
	
		while ((vector[i] > x && !ascending)||(vector[i] < x && ascending)) {
			i++;
		}
		//ignore all numbers lesser than X to right
		while ((vector[j] < x&& !ascending)||(vector[j] > x && ascending)) {
			j--;
		}

		//swap a number lesser than X on left with a number greater than X on right
		if (i < j) {
			int temp = vector[i];
			vector[i] = vector[j];
			vector[j] = temp;
			i++;
			j--;
		}
		else {
			//Now the array is so sorted, that all numbers lesser than X are on right of it and greater than X are to left of it. Hence return position of X
			return j;
		}
	}
	
}

void Sort::quickSort(int start, int end, bool descending) {
	if (start < end) {
		
		int p = partition(start,end, descending);

		quickSort(start,p, descending);
		quickSort(p + 1, end, descending);
	}
}



void Sort::QuickSort(bool ascending) {
	quickSort(0, count - 1, ascending);
}

void Sort::Print() {
	for (int i = 0; i < count; ++i) {
		printf("%d ", vector[i]);
	}
	printf("\n");
}

int Sort::GetElementsCount() {
	return count;
}

int Sort::GetElementFromIndex(int index) {
	return vector[index];
}

Sort::~Sort() {
	delete[] vector;
}