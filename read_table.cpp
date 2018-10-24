
#include<iostream>
#include<string>
#include<fstream>
#include"Element.h"

int read_table(Element **&table);

using namespace std;

struct Node {
	Element *pElement;
	Node *next;
};

int read_table(Element **&table) {
	ifstream infile;
	infile.open("periodictable.dat");
	
	if (!infile.is_open()) {
		return 0;
	}

	int n = 0;
	Node *head = NULL;
	Node *temp = NULL;

	Element e;

	while (!infile.eof())
	{
		infile >> e.atomicNum >> e.abbrev >> e.mass >> e.name;
		if (e.atomicNum == 0 || e.abbrev.empty() || e.mass == 0 || e.name.empty()) {
			infile.close();
			return 0;
		}
		Node *pn = new Node;
		pn->pElement = new Element;
		*(pn->pElement) = e;
		if (n == 0) {
			head = pn;
			temp = pn;
		}
		else {
			temp->next = pn;
			temp = temp->next;
		}
		n++;
	}
	infile.close();
	
	table = new Element*[n];
	for (int i = 0;i < n;i++) {

		table[i] = head->pElement;
		temp = head;
		head = head->next;
		delete temp;
	}
	

	return n-1;
}
