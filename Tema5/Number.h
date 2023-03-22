#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
class Number

{

	// add data members
	int base;
	char* value;
	static int myatoi(const char *sir);

public:

	Number(const char* value, int base); // where base is between 2 and 16
	Number(const Number& n);
	Number(Number&& n);
	Number(int value);
	~Number();

	// add operators and copy/move constructor
	
	
	
	
	friend Number operator+(const Number& left, const Number& right);
	friend Number operator-(const Number& left, const Number& right);
	bool operator>(const Number& other);
	bool operator>=(const Number& other);
	bool operator<(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	bool operator!=(const Number& other);
	Number& operator=(const Number& n);
	Number& operator=(Number&& n);


	char operator[](int index);
	Number operator--(); 
	Number operator--(int); 
	Number operator++();
	Number operator++(int);
	


	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};