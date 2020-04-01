#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> calc5(int a, int b) {
	vector<int> result;

	do {
		if (a % 2 == 0) {
			result.push_back(a);
		}
		a++;
	} while(a <= b);

	return result;
}

void testTask5() {
	vector<map<string, int>> cc  = {
		{{"a", 1}, {"b", 1}},
		{{"a", 1}, {"b", 2}},
		{{"a", 2}, {"b", 3}},
		{{"a", 2}, {"b", 2}},
		{{"a", 2}, {"b", 4}},
		{{"a", 1}, {"b", 4}},
	};

	vector<vector<int>> results = {
		{},
		{2},
		{2},
		{2},
		{2, 4},
		{2, 4}
	};

	map<string, int> c;
	for (uint i = 0; i < cc.size(); ++i) {
		c = cc[i];
		cout << "Tests case #" << i+1 << " " << (calc5(c["a"], c["b"]) == results[i] ? "OK" : "FAIL") << endl;
	}
}

int task5() {
//	tests();
	int a, b;
	cin >> a >> b;

	vector<int> rr = calc5(a, b);
	for (auto r : rr) {
		cout << r << " ";
	}

	return 0;
}
