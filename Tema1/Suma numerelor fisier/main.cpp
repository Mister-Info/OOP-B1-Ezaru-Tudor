#include <iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int s, n;
int myatoi(const char* sir) {

    int nou = 0;
    for (int i = 0; i < strlen(sir); ++i)
    {
        nou = nou * 10 + (sir[i] - '0');
    }
    return nou;
}


int main()
{
    FILE* fisier;
    fisier = fopen("C:\\Fisiere\\ini.txt", "r");

    char x[101];

    if (fisier == NULL)
    {
        printf("fisierul nu exista");
        return 0;
    }

    s = 0;

    while (!feof(fisier))
    {
        n = 0;
        fscanf(fisier, "%s", x);
        n = myatoi(x);
        s += n;

    }
    fclose(fisier);
    printf("%d", s);

    return 0;
}



