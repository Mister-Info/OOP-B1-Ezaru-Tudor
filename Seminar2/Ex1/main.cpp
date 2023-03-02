#define _CRT_SECURE_NO_WARNINGS

#include "NumberList.h"

int main()
{
	NumberList numbers;
	numbers.Init();
	numbers.Add(4);
	numbers.Add(6);
	numbers.Add(1);
	numbers.Sort();
	numbers.Print();
}

