#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "global.h" 
using namespace std;
int main()
{
	Student a;
	Student b;
	a.SetName("Robert");
	a.SetEng(5);
	a.SetHis(10);
	a.SetMath(9);
	a.Avg();

	b.SetName("Andra");
	b.SetEng(10);
	b.SetHis(10);
	b.SetMath(2);
	b.Avg();

	cout<<compareName(a, b)<<endl;
	cout<<compareEng(a, b)<<endl;
	cout<<compareHis(a, b)<<endl;
	cout<<compareMath(a, b)<<endl;
	cout<<compareAvg(a, b);


	
	
}


