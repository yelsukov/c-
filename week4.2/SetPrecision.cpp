#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int SetPrecision() {
	ifstream input("input.txt");
	cout << fixed << setprecision(3);

	if (input.is_open()) {
		double line;
		while(input >> line) {
			cout << line << endl;
		}
	} else {
		cout << "Can not open file" << endl;
	}
	return 0;
}
