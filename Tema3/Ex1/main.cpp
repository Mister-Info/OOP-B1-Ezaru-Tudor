#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"

#include <iostream>

int main()
{
    
    printf("%d\n", Math::Add(23, 12));
    printf("%d\n", Math::Add(1, 2, 3));
    printf("%f\n", Math::Add(12.3, 1.8));
    printf("%f\n", Math::Add(12.3, 1.8, 3.4));
    printf("%d\n", Math::Mul(2, 3));
    printf("%d\n", Math::Mul(2, 3, 4));
    printf("%f\n", Math::Mul(2.5, 2.3));
    printf("%f\n", Math::Mul(2.1,3.2,4.3));
    printf("%d\n", Math::Add(3, 5, 6, 7));
    char* s = Math::Add("seminar3", "oop");
    printf("%s\n", s);
    delete[] s;
    
    
}

