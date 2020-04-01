#include <iostream>
#include <map>
#include <vector>

using namespace std;

int calc6(int a, int b) {
	while(a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}

	return a + b;
}

void tests6() {
	vector<map<string, int>> cc  = {
		{{"a", 25}, {"b", 27}, {"r", 1}},
		{{"a", 12}, {"b", 16}, {"r", 4}},
		{{"a", 13}, {"b", 13}, {"r", 13}},


		{{"a", 1}, {"b", 1}, {"r", 1}},
		{{"a", 0}, {"b", 10}, {"r", 10}},
		{{"a", 27}, {"b", 0}, {"r", 27}},
		{{"a", 0}, {"b", 0}, {"r", 0}},
		{{"a", 27}, {"b", 25}, {"r", 1}},
	};

	int i = 0;
	for (auto c : cc) {
		i++;
		cout << "Tests case #" << i << " " << (calc6(c["a"], c["b"]) == c["r"] ? "OK" : "FAIL") << endl;
	}
}

int main6() {
//	tests();
	int a, b;
	cin >> a >> b;
	cout << calc6(a, b);

	return 0;
}
