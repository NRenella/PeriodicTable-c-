#include<string>

using namespace std;

struct Element {
	int atomicNum;
	string abbrev;
	string name;
	float mass;
};

int read_table(Element **&table);

