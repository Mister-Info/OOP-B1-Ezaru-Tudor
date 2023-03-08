#define _CRT_SECURE_NO_WARNINGS

#include "Math.h"
#include<cstdio>
#include<stdarg.h>
#include<cstring>
#include<algorithm>

int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}

double Math::Add(double x, double y) {
	return x + y;
}

double Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

double Math::Mul(double x, double y) {
	return x * y;
}

double Math::Mul(double x, double y, double z) {
	return x * y * z;
}

int Math::Add(int count, ...) {

	int sum = 0;
	va_list argptr;
	va_start(argptr, count);

	for (int i = 0; i < count;++i) {
		int n = va_arg(argptr, int);
		sum += n;
		
	}
	va_end(argptr);
	return sum;
}

char* Math::Add(const char* s1, const char* s2) {
	char* s=new char[20];
	strcpy(s, s1);
	strcat(s, s2);
	return s;
}
