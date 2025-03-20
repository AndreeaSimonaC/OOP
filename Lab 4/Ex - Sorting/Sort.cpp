#include "Sort.h"

Sort::Sort(int nrElemente, int min, int max){
	if (min > max || nrElemente <= 0) return;

	dimensiune = nrElemente;
	elements = new int[dimensiune];
	srand(time(nullptr));

	for (int i = 0; i < dimensiune; i++) {
		elements[i] = rand() % (max - min + 1) + min;
	}
}


Sort::Sort(int v[], int nrElemente)
{
	if (nrElemente <= 0) return;
	a = new int[nrElemente];
	for (int i = 0; i < nrElemente; i++) {
		a[i] = v[i];
	}
}
Sort::Sort(int nrElemente, ...)
{
	if (nrElemente <= 0) return;
	a = new int[nrElemente];
	va_list l;
	va_start (l, nrElemente)
		for (int i = 0; i < nrElemente; i++) {
			a[i] = va_arg(l, int);
		}
	va_end(l);
}

Sort::Sort(const char* numbers) {
	char temp[256];
	strncpy(temp, numbers, sizeof(temp));
	temp[255] = '\0'; // Ensure null termination

	dimensiune = 1; // Count numbers
	for (int i = 0; temp[i]; i++) {
		if (temp[i] == ',') dimensiune++;
	}

	elements = new int[dimensiune];
	int index = 0;
	char* token = strtok(temp, ",");

	while (token) {
		elements[index++] = atoi(token);
		token = strtok(nullptr, ",");
	}
}


void Sort::InsertSort(bool ascending) {
	for (int i = 1; i < dimensiune; i++) {
		int key = elements[i];
		int j = i - 1;

		while (j >= 0 && ((ascending && elements[j] > key) || (!ascending && elements[j] < key))) {
			elements[j + 1] = elements[j];
			j--;
		}
		elements[j + 1] = key;
	}
}
int Sort::Partition(int stanga, int dreapta, bool ascending) {
	int pivot = elements[dreapta];
	int i = stanga - 1;

	for (int j = stanga; j < dreapta; j++) {
		if ((ascending && elements[j] < pivot) || (!ascending && elements[j] > pivot)) {
			i++;
			swap(elements[i], elements[j]);
		}
	}
	swap(elements[i + 1], elements[dreapta]);
	return i + 1;
}
void Sort::QuickSortHelper(int stanga, int dreapta, bool ascending) {
	if (stanga < dreapta) {
		int pivotIndex = Partition(stanga, dreapta, ascending);
		QuickSortHelper(stanga, pivotIndex - 1, ascending);
		QuickSortHelper(pivotIndex + 1, dreapta, ascending);
	}
}
void Sort::QuickSort(bool ascending) {
	QuickSortHelper(0, dimensiune - 1, ascending);
}

void Sort::BubbleSort(bool ascending) {
	bool swapped;
	for (int i = 0; i < dimensiune - 1; i++) {
		swapped = false;
		for (int j = 0; j < dimensiune - i - 1; j++) {
			if ((ascending && elements[j] > elements[j + 1]) || (!ascending && elements[j] < elements[j + 1])) {
				swap(elements[j], elements[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;//sortat
	}
}

void Sort::Print() {
	for (int i = 0; i < dimensiune; i++) {
		cout << elements[i] << " ";
	}
	cout << endl;
}
int Sort::GetElementsCount() {
	return dimensiune;
}


int Sort::GetElementFromIndex(int index) {
	if (index >= 0 && index < dimensiune) {
		return elements[index];
	}
	return -1; //daca index-out of bounds
}
