#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int table() {
	ifstream input ("input.txt");

	uint n, m;
	input >> n >> m;

	uint cellQty = n * m;
	for (uint i = 1; i <= cellQty; i++) {
		int cell;
		input >> cell;

		cout << setw(10) << cell;
		if (i % m != 0) {
			cout << " ";
			input.ignore(1);
		} else if (i != cellQty) {
			cout << endl;
		}
	}

	return 0;
}
