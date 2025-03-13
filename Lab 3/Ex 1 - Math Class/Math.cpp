#include "Math.h"
#include <iostream>
#include <cstdarg>
#include <cstring>

using namespace std;

int Math::Add(int n, int m) {
	return n + m;
}
int Math::Add(int n, int m, int p) {
	return n + m + p;
}
int Math::Add(double n, double m) {
	return n + m;
}
int Math::Add(double n, double m, double p) {
	return n + m + p;
}
int Math::Mul(int a, int b) {
	return a * b; 
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return a * b; 
}
int Math::Mul(double a, double b, double c) {
	return a * b * c;
}
int Math::Add(int count, ...) {
	va_list p;
	va_start(p, count);

	int i, suma;
	for (i = 0, suma = 0; i < count; i++) {
		suma = suma + va_arg(p, int);
	}

	va_end(p);
	return suma;
}
char* Math::Add(const char* stringOne, const char* stringTwo) {

	int totalLength = strlen(stringOne) + strlen(stringTwo) + 1; //1 pt null la final
	char* result = new char[totalLength];

	strcpy(result, stringOne);
	strcat(result, stringTwo);

	return result;

};