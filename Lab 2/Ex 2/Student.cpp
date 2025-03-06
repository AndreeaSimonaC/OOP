#include "Student.h"
using namespace std;

bool Student::setNume(const char* p) {
	if (p == nullptr)
		return 0;
	for (int i = 0; i < 30; i++) {
		nume[i] = 0;
	}
	for (int i = 0; i < 30; i++) {
		nume[i] = 0;
	}
}
char* Student::getNume()
{
    return nume;
}

bool Student::setMat(int x)
{
    if (x < 1 || x>10) return 0;
    mat = x;
    return 1;
}

int Student::getMat()
{
    return mat;
}

bool Student::setIst(int x)
{
    if (x < 1 || x>10) return 0;
    ist = x;
    return 1;
}

int Student::getIst()
{
    return ist;
}

bool Student::setEng(int x)
{
    if (x < 1 || x>10) return 0;
    eng = x;
    return 1;
}

int Student::getEng()
{
    return eng;
}

double Student::avg()
{
    double aux;
    aux = ((double)mat + ist + eng) / 3;
    return aux;
}