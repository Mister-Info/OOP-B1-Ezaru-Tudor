#include <ctime>
#include <iostream>
#include "Sort.h"
int main()
{
	srand(time(NULL));
	Sort l(4, 3, 10);
	l.Print();
	printf("\n");
	l.QuickSort(false);
	l.Print();
	l.QuickSort(true);
	l.Print();

	
	Sort q(4, 4, 5, 11, 7);
	q.InsertSort(false);
	q.Print();
	q.InsertSort(true);
	q.Print();
	q.BubbleSort(false);
	q.Print();
	q.BubbleSort(true);
	q.Print();
	
	

}

