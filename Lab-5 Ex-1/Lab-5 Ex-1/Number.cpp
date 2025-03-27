#include "Number.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

Number::Number(const char* value, int base) : base(base) {
    if (base < 2 || base > 16) {
        throw std::invalid_argument("Baza nu este intr 2 si 16");
    }

    digitCount = strlen(value);
    this->value = new char[digitCount + 1];
    strcpy_s(this->value, sizeof(this->value), value);
    removeZerosInFront();
}

Number::Number(int value) : base(10) {
    if (value == 0) {
        this->value = new char[2];
        this->value[0] = '0';
        this->value[1] = '\0';
        digitCount = 1;
        return;
    }

    //valori negative
    bool isNegative = value < 0;
    unsigned int absoluteValue = abs(value);

    //numaram cifrele
    digitCount = 0;
    unsigned int temp = absoluteValue;
    while (temp != 0) {
        temp /= 10;
        digitCount++;
    }

    //alocam memorie - si pentru null terminator
    this->value = new char[digitCount + (isNegative ? 2 : 1)];

    //reverse string
    int index = digitCount;
    temp = absoluteValue;
    while (temp != 0) {
        this->value[--index] = '0' + (temp % 10);
        temp /= 10;
    }

    //adaguam semnul pt negativ
    if (isNegative) {
        // Shift fiecare cifra la dreapta
        for (int i = digitCount; i >= 0; i--) {
            this->value[i + 1] = this->value[i];
        }
        this->value[0] = '-';
        digitCount++;
    }

    //null terminator
    this->value[digitCount] = '\0';
}

Number::~Number() {
    delete[] value;
}

//Copy constructor
Number::Number(const Number& other) {
    base = other.base;
    digitCount = other.digitCount;
    value = new char[digitCount + 1];

    strcpy_s(value, sizeof(value), other.value);
}

//Copy assignment
Number& Number::operator=(const char* value) {
    //Convert la baza curenta
    int tempBase = this->base; //curr base
    Number temp(value, 10);    //pp ca e baza 10
    temp.SwitchBase(tempBase); //convert la baza initiala

    //cleanup
    delete[] this->value;

    //Copy valoare noua
    this->digitCount = temp.digitCount;
    this->value = new char[digitCount + 1];
    strcpy_s(this->value, sizeof(this->value), temp.value);
    return *this;
}

//Move constructor
Number::Number(Number&& other) noexcept {
    base = other.base;
    digitCount = other.digitCount;
    value = other.value;
    other.value = nullptr;
}

//Move assignment
Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        base = other.base;
        digitCount = other.digitCount;
        value = other.value;
        other.value = nullptr;
    }
    return *this;
}

int Number::charToDigit(char c) const {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return 10 + c - 'A';
    if (c >= 'a' && c <= 'f') return 10 + c - 'a';
    throw std::invalid_argument("Invalid digit");
}

char Number::digitToChar(int d) const {
    if (d < 10) return '0' + d;
    return 'A' + (d - 10);
}

void Number::convertToBase(int newBase) {
    if (newBase == base) return;

    //Conv la b10
    int decimalValue = 0;
    for (int i = 0; i < digitCount; i++) {
        decimalValue = decimalValue * base + charToDigit(value[i]);
    }

    //Conv la baza nout
    if (decimalValue == 0) {
        delete[] value;
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
        digitCount = 1;
        base = newBase;
        return;
    }

    char* newValue = new char[32];
    int index = 0;
    while (decimalValue > 0) {
        newValue[index++] = digitToChar(decimalValue % newBase);
        decimalValue /= newBase;
    }
    newValue[index] = '\0';

    //Reverse string
    for (int i = 0; i < index / 2; i++) {
        std::swap(newValue[i], newValue[index - 1 - i]);
    }

    delete[] value;
    value = newValue;
    digitCount = index;
    base = newBase;
}

void Number::removeZerosInFront() {
    int firstNonZero = 0;
    while (firstNonZero < digitCount && value[firstNonZero] == '0') {
        firstNonZero++;
    }

    if (firstNonZero == digitCount) {
        //pastram doar un 0
        value[0] = '0';
        value[1] = '\0';
        digitCount = 1;
        return;
    }

    if (firstNonZero > 0) {
        digitCount -= firstNonZero;
        for (int i = 0; i <= digitCount; i++) {
            value[i] = value[i + firstNonZero];
        }
    }
}

Number operator+(const Number& n1, const Number& n2) {
    int maxBase = std::max(n1.base, n2.base);
    Number temp1 = n1;
    Number temp2 = n2;
    temp1.convertToBase(10);
    temp2.convertToBase(10);

    int sum = atoi(temp1.value) + atoi(temp2.value);
    Number result(sum);
    result.convertToBase(maxBase);
    return result;
}

Number operator-(const Number& n1, const Number& n2) {
    int maxBase = std::max(n1.base, n2.base);
    Number temp1 = n1;
    Number temp2 = n2;
    temp1.convertToBase(10);
    temp2.convertToBase(10);

    int diff = atoi(temp1.value) - atoi(temp2.value);
    Number result(diff);
    result.convertToBase(maxBase);
    return result;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator-=(const Number& other) {
    *this = *this - other;
    return *this;
}

Number& Number::operator--() {
    //Prefix: elim prima cifra
    if (digitCount <= 1) {
        value[0] = '0';
        value[1] = '\0';
        digitCount = 1;
        return *this;
    }

    for (int i = 0; i < digitCount; i++) {
        value[i] = value[i + 1];
    }
    digitCount--;
    return *this;
}

Number Number::operator--(int) {
    //Postfix: elim ultima cifra
    Number temp(*this);
    if (digitCount <= 1) {
        value[0] = '0';
        value[1] = '\0';
        digitCount = 1;
    }
    else {
        value[digitCount - 1] = '\0';
        digitCount--;
    }
    return temp;
}

char Number::operator[](int index) const {
    if (index < 0 || index >= digitCount) {
        throw out_of_range("Index out of range");
    }
    return value[index];
}

bool Number::operator>(const Number& other) const {
    Number temp1 = *this;
    Number temp2 = other;
    temp1.convertToBase(10);
    temp2.convertToBase(10);
    return atoi(temp1.value) > atoi(temp2.value);
}

bool Number::operator<(const Number& other) const {
    return other > *this;
}

bool Number::operator>=(const Number& other) const {
    return !(*this < other);
}

bool Number::operator<=(const Number& other) const {
    return !(*this > other);
}

bool Number::operator==(const Number& other) const {
    Number temp1 = *this;
    Number temp2 = other;
    temp1.convertToBase(10);
    temp2.convertToBase(10);
    return atoi(temp1.value) == atoi(temp2.value);
}

bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

Number::operator int() const {
    Number temp = *this;
    temp.convertToBase(10);
    return atoi(temp.value);
}

void Number::SwitchBase(int newBase) {
    convertToBase(newBase);
}

void Number::Print() const {
    std::cout << value << " (base " << base << ")" << std::endl;
}

int Number::GetDigitsCount() const {
    return digitCount;
}

int Number::GetBase() const {
    return base;
}