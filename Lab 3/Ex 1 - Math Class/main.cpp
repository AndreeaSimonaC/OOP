#include "Math.h";
#include <iostream>;

using namespace std;

int main() {

	int suma1 = Math::Add(2, 3);
	cout << "Add(int, int): 2 + 3 = " << suma1 << endl;

	int suma2 = Math::Add(2, 3, 4);
	cout << "Add(int, int, int): 2 + 3 + 4= " << suma2 << endl;

	int suma3 = Math::Add(2.1, 3,1);
	cout << "Add(double, double): 2.1 + 3.1 = " << suma3 << endl;

	int suma4 = Math::Add(2.1, 3.1, 4.1);
	cout << "Add(double, double, double): 2.1 + 3.1 + 4.1= " << suma4 << endl;

	int product1 = Math::Mul(2, 3);
	cout << "Mul(int, int): 2 * 3 = " << product1 << endl;

	int product2 = Math::Mul(2, 3, 4);
	cout << "Mul(int, int, int): 2 * 3 * 4 = " << product2 << endl;

	int product3 = Math::Mul(2.1, 3.1);
	cout << "Mul(double, double): 2.1 * 3.1 = " << product3 << endl;

	int product4 = Math::Mul(2.1, 3.1, 4.1);
	cout << "Mul(double, double, double): 2.1 * 3.1 * 4.1 = " << product4 << endl;

	int sumCuCount = Math::Add(4, 1, 2, 3, 4);
	cout << "Add(int count, ... ): 1 + 2 + 3 + 4 = " << sumCuCount << endl;

	const char* stringOne = "My name is ";
	const char* stringTwo = "Andreea";
	char result = Math::Add(stringOne, stringTwo);
	cout << "Add(const char*, const char* ): " << result << endl;
	delete[] result; // free memory


	return 0;
}