#include "NumberList.h" 
using namespace std;

int main()
{
	NumberList* a = new NumberList();

	a->Init();
	a->Add(1);
	a->Add(2);
	a->Add(9);
	a->Add(11);

	cout << "a list:\n\n";
	a->Print();
	a->Sort();
	cout << "a sorted list:\n\n";
	a->Print();
	return 0;
}