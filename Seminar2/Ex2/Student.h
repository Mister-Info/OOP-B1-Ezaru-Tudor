#pragma once
class Student
{
	float eng, his, math;
	char name[256];


public:
	void SetName(const char* name);

	const char* GetName();

	void SetMath(float x);
	float GetMath();

	void SetEng(float x);
	float GetEng();

	void SetHis(float x);
	float GetHis();
	
	float Avg();



};