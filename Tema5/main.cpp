#include "Number.h"

int main()

{

    Number n1("111", 10);

    Number n2("102", 10);

    Number n3("FF", 16);



    printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());    
    
    n1.Print();
    n2.Print();
    n2.Print();
    
    return 0;
    
}

