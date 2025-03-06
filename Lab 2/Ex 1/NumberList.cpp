#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init() {

	counter = 0;

}

bool NumberList::Add(int x) {

    if (counter + 1 >= 10) return 0;

    numbers[counter++] = x;
    return 1;

}

void NumberList::Print() {

    for (int i = 0; i < counter; i++)
        cout << numbers[i] << '\n';

}

void NumberList::Sort() {

    bool found;
    int aux, i;

    do
    {
        found = 0;
        for (i = 0; i < counter - 1; i++)
            if (numbers[i] > numbers[i + 1])
            {
                found = 1;
                aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
    } while (found);

}