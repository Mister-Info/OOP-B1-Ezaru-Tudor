#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include<cstdio>
#include<cstring>
#include<algorithm>

void Student::SetName(const char* name) {
	strcpy(this->name, name);
}

void Student::SetMath(float x) {
	if (x >= 1 && x <= 10) {
		math = x;
	}
}

void Student::SetEng(float x) {
	if (x >= 1 && x <= 10) {
		eng = x;
	}
}

void Student::SetHis(float x) {
	if (x >= 1 && x <= 10) {
		his = x;
	}
}

float Student::Avg() {
	return (math+his+eng)/3;
}

const char* Student::GetName()
{
	return name;
}

float Student::GetMath() {
	return math;
}

float Student::GetEng() {
	return eng;
}

float Student::GetHis() {
	return his;
}
