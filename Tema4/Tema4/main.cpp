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

	
	
	
	
	
	

}

