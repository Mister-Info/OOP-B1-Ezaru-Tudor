#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "Canvas.h"
#include<cstdio>
#include<stdarg.h>
#include<cstring>
#include<algorithm>
#include<iostream>

#include<cmath>


Canvas::Canvas(int width, int height) : widthM(width), heightM(height) {
	matrix = new char* [heightM];
	for (int i = 0; i < heightM; ++i) {
		matrix[i] = new char[widthM];
		for (int j = 0; j < widthM; ++j) {
			matrix[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    
	
	for (int ungle = 0; ungle < 360; ungle = ungle + 1)
	{
	int x1 = x + ray * cos(ungle*M_PI/180);
	int y1 = y + ray * sin(ungle*M_PI/180);
		SetPoint(x1, y1, ch);
	}

}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	
	while (ray > 0) {
		DrawCircle(x, y, ray, ch);
		--ray;
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	
	if (left > right)
	{
		DrawRect(right, top, left, bottom, ch);
		return;
	}

	if (top > bottom) {

		DrawRect(left, bottom, right, top, ch);
		return;
	}
	for (int i = left; i <= right; ++i) {
		SetPoint(i, top, ch);
	}
	for (int j = top; j <= bottom; ++j) {
		SetPoint(left, j, ch);
	}
	for (int i = right; i >= left; --i) {
		SetPoint(i, bottom, ch);
	}
	for (int j = bottom; j >= top; --j) {
		SetPoint(right, j, ch);
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	if (left > right)
	{
		FillRect(right, top, left, bottom, ch);
		return;
	}

	if (top > bottom) {

		FillRect(left, bottom, right, top, ch);
		return;
	}

	for (int i = left; i <= right; ++i) {
		for (int j = top; j <= bottom; ++j) {
			SetPoint(i, j, ch);
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	if (x > 0 && x < widthM && y > 0 && y < heightM) {
		matrix[x][y] = ch;
	}
	return;
}


void Canvas::Print()
{
	for (int i = 0; i < widthM; ++i)
	{
		for (int j = 0; j < heightM; ++j)
			printf("%c ", matrix[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < heightM; ++i) {
		delete[] matrix[i];
		
	}
	delete[] matrix;
}