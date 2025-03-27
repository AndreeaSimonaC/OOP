#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class Number
{

private:
	char* value;
	int base;
	int digitCount;

	int charToDigit(char c) const;
	char digitToChar(int d) const;
	void convertToBase(int newBase);
	void removeZerosInFront();

public:
	Number(const char* value, int base);
	Number(int value);
	~Number();

	//copy constructor cu asignare
	Number(const Number& other);
	Number& operator=(const char* value);

	//move constructor cu asignare
	Number(Number&& other) noexcept;
	Number& operator=(Number&& other) noexcept;

	//operatori matematici
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	Number& operator+=(const Number& other);
	Number& operator-=(const Number& other);

	//increment/decrement
	Number& operator--();    
	Number operator--(int);  

	//index operator
	char operator[](int index) const;

	//comparatori
	bool operator>(const Number& other) const;
	bool operator<(const Number& other) const;
	bool operator>=(const Number& other) const;
	bool operator<=(const Number& other) const;
	bool operator==(const Number& other) const;
	bool operator!=(const Number& other) const;

	//pt conversie
	operator int() const;

	void SwitchBase(int newBase);
	void Print() const;
	int  GetDigitsCount() const;
	int  GetBase() const;
};