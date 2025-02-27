#include <iostream>
using namespace std;

bool checkPrime(int number)
{
    for (int tr = 2; tr * tr <= number; tr++)
        if (number % tr == 0)
            return false;
    return true;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (checkPrime(number))
        cout << number << " is a prime number";
    else
        cout << number << "is NOT a prime number";
    return 0;
}