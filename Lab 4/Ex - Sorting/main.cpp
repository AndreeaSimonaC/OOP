#include "Sort.h"
#include <iostream>

using namespace std;

int main() {
    //lista constructor implicit (10-1 descrescator)
    cout << "Lista initiala (constructor implicit):" << endl;
    Sort s1;
    s1.Print();

    //lista cu numere random intre 10 si 50, cu 8 elemente
    cout << "Lista random cu 8 elemente intre 10 si 50:" << endl;
    Sort s2(8, 10, 50);
    s2.Print();

    //lista dintr-un vector existent
    int arr[] = { 5, 2, 9, 1, 6 };
    cout << "Lista creata dintr-un vector existent:" << endl;
    Sort s3(arr, 5);
    s3.Print();

    //lista variadic arguments
    cout << "Lista creata folosind variadic arguments:" << endl;
    Sort s4(6, 7, 3, 8, 2, 5, 10);
    s4.Print();

    //lista dintr-un sir de car
    cout << "Lista creata dintr-un sir de caractere \"20,4,50,7,13\":" << endl;
    Sort s5("20,4,50,7,13");
    s5.Print();

    //Bubble Sort in ordine ascendenta
    cout << "Bubble Sort in ordine ascendenta:" << endl;
    s2.BubbleSort(true);
    s2.Print();

    //Insert Sort in ordine descendenta
    cout << "Insert Sort in ordine descendenta:" << endl;
    s3.InsertSort(false);
    s3.Print();

    //Quick Sort in ordine ascendenta
    cout << "Quick Sort in ordine ascendenta:" << endl;
    s4.QuickSort(true);
    s4.Print();

    //numarul total de elemente din lista
    cout << "Numarul total de elemente din lista s5: " << s5.GetElementsCount() << endl;

    //Accesare element dupa index
    int index = 2;
    cout << "Elementul de la indexul " << index << " din lista s5: " << s5.GetElementFromIndex(index) << endl;
    return 0;
}