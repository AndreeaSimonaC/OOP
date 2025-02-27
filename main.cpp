#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {

	ifstream f("ini.txt");
	int c;
	f >> c;
	printf(c);

}