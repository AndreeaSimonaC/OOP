#include <iostream>
#include<fstream>
#include <cstring>

using namespace std;

char s[30];
long long int suma, nnumar, i;

int main()
{
    FILE* input;
    input = fopen("./ini.txt", "r");

    while (fscanf(input, "%s", s) != EOF)
    {
        numar = 0;
        for (i = 0; s[i]; i++) {
            numar = numar * 10 + s[i] - '0';
        }
        suma += numar;
    }

    cout << suma;
    return 0;
}