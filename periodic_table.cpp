//
// Name: Renella, Noah
// Project: #3
// Due: 10/22/2018
// Course: CS-2560-02-F18
//
// Description:
// In this project we take a look at pointers, structures and arrays to merge all of them together and create an array of pointers to elements.
// This porject was very interesting because we had to take all the knowledge we took from class and apply them to this piece of code.
// To make it brief we took a periodic table from a file made it to an array of pointers and sorted that array according to the name.
//

#include<iostream>
#include<string>
#include<iomanip>
#include"Element.h"

void Sort(Element **table, int size);
int compareNames(Element *e1, Element *e2);

using namespace std;



int main() {

	Element **table;
	float average = 0;
	int n = read_table(table);
        
	if (n == 0) {
		cerr << "Unable to load the periodic table data file " << endl;
		exit(EXIT_FAILURE);
	}
	Sort(table, n);
	cout << "Periodic Table by N. Renella" << endl;
	cout << endl;
	cout << "Number of elements: " << n << endl;
	cout << endl;
	cout << "Name                 Abr  ANo    Mass" << endl;
	cout << "-------------------- --- ---- -------" << endl;
	cout << setprecision(2) << fixed;

	for (int i = 0;i < n;i++) {
		cout << left << setw(20)<< table[i]->name << " " <<setw(3) << table[i]->abbrev << " " << right  << setw(4) << table[i]->atomicNum << " " <<  setw(7) << table[i]->mass << endl;
		average += table[i] -> mass;
	}

	cout << endl;
	cout << "The average mass:" << setw(20) << average / n << endl;
	
	return 0;
}

int compareNames(Element *e1, Element *e2) {
	return e1->name < e2->name;
}


void Sort(Element **table, int size) {
	int startScan, index, minIndex;
	Element *minValue;

	for (startScan = 0; startScan < size - 1; startScan++) {
		minIndex = startScan;
		minValue = table[startScan];
		for (index = startScan + 1;index < size; index++) {
			if (compareNames(table[index], minValue)) {
				minValue = table[index];
				minIndex = index;
			}
		}
		table[minIndex] = table[startScan];
		table[startScan] = minValue;
	}
}

