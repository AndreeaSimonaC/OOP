#include <iostream>
using namespace std;

class Sort
{
private: 
    int* elements;    
    int dimensiune; 
    int Partition(int stanga, int dreapta, bool ascending);
    void QuickSortHelper(int stanga, int dreapta, bool ascending);

public:
    //constuctors:
    //default
    Sort();
    /*create the list that needs to be sorted out of random values within a specific interval(min, max).
      The constructor will receive 3 parameters (the number of elements in the list, minimum value, maximum value).*/
    Sort(int nrElemente, int min, int max);
    //create the list that needs to be sorted from an initialization list
   // ????????
    /*create the list that needs to be sorted from an existing vector
       (the constructor will have two parameters - one being the vector, 
       the other one being the number of elements from the vector)*/
    Sort(int v[], int nrElemente)

    //create the list that needs to be sorted using variadic parameters(use va_args for this)
    Sort(int nrElemente, ...);

    /*create the list that needs to be sorted from a string(e.g. "10,40,100,5,70"->
       each number is separated from the rest of the number with a comma).
       It is assumed that the string is correctly written(no space, only numerical characters and commas*/
    Sort(const char* numbers);

    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};