#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int Factorial(int n) {
	return n <= 1 ? 1 : n  * Factorial(n - 1);
}

void tests9() {
	vector<map<string, int>> cc  = {
		{{"n", 0}, {"r", 1}},
		{{"n", -1}, {"r", 1}},
		{{"n", 1}, {"r", 1}},
		{{"n", 2}, {"r", 2}},
		{{"n", 4}, {"r", 24}},
	};

	int i = 1;
	for (auto c : cc) {
		cout << "Tests case #" << i << " "<< (Factorial(c["n"]) == c["r"] ? "OK" : "FAIL") << endl;
		i++;
	}
}

int main9() {
//	tests();
	int n;
	cin >> n;
	cout << Factorial(n);

	return 0;
}
