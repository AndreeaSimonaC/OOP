#include <iostream>
#include<fstream>
#include <cstring>

using namespace std;

struct words
{
    char words[256];
    int length;
} arr[100];

char sentence[256], * p;
int wordsNumber, i;

void sort(words v[100]);
bool ok(words a, words b);

int main()
{
    scanf("%[^\n]", sentence);
    p = strtok(sentence, " ");
    while (p)
    {
        strcpy(arr[wordsNumber].words, p);
        arr[wordsNumber].length = strlen(arr[wordsNumber++].words);
        p = strtok(NULL, " ");
    }
    sort(arr);
    for (i = 0; i < wordsNumber; i++)
        cout << arr[i].words << '\n';
    return 0;
}

void sort(words v[])
{
    words aux;
    bool found = 0;
    int i;

    do
    {
        found = 0;
        for (i = 0; i < wordsNumber - 1; i++)
            if (!ok(v[i], v[i + 1]))
            {
                found = 1;
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
            }
    } while (found);

}

bool ok(words a, words b)
{
    return ((a.length > b.length) || (a.length == b.length && strcmp(a.words, b.words) > 0));
}