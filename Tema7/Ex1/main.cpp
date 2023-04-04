#include <iostream>
#include <cstring>

long double operator"" _Kelvin(unsigned long long x) {

    return x - 273.15;
    
}

long double operator"" _Fahrenheit(unsigned long long x) {

    return (x - 32) * 5 / 9;

}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    printf("%f\n", a);
    printf("%f\n", b);


}