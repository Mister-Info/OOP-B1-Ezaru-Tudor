#pragma once
#include <initializer_list>
class Sort
{
private:
    int count;
    int* vector;
    int partition(int start, int end,bool descending);
    void quickSort(int start, int end, bool desending);
   

public:

    Sort(int count, int minim, int maxim);

    Sort(std::initializer_list<int> l);

    Sort(int* vector, int count);

    Sort(int count, ...);

    Sort(const char* s);

    ~Sort();

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};