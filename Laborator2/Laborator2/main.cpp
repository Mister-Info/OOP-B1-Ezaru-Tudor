#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
using namespace std;

struct nume {
	char a;
	int b;
	short c, d;
};


struct nume2 {
	char arr[6];
	char arr2[3];
};


int main()
{
	nume a = {0};
	nume c;
	nume2 b;

	memset(&b, 1, sizeof(b));
	b.arr2[2] = 1;
	printf("%d",((nume*)&b)->d);
	
}
