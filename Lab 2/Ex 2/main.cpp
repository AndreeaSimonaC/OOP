#include <iostream>
#include "Global.h"

using namespace std;

int main()
{
	Student a, b;
	a.setNume("Andreea");
	a.setEng(9);
	a.setIst(4);
	a.setMat(7);
	b.setNume("Simona");
	b.setEng(8);
	b.setIst(7);
	b.setMat(6);
	cout << "Compara numele: " << comparNume(a, b) << '\n';
	cout << "Compara notele eng: " << comparEng(a, b) << '\n';
	cout << "Compara notele ist: " << comparIst(a, b) << '\n';
	cout << "Compara notele mat: " << comparMat(a, b) << '\n';
	cout << "Compara avg: " << comparAvg(a, b) << '\n';
	return 0;
}