#include <iostream>
#include <map>
#include <vector>

using namespace std;

int calcTask3(int x, int y) {
	return y != 0 ? (x / y) : -1;
}

void test() {
	vector<map<string, int>> cc = {
			{{"x",1}, {"y", 2}, {"r", 0}},
			{{"x",0}, {"y", 1}, {"r", 0}},
			{{"x",1}, {"y", 1}, {"r", 1}},
			{{"x",2}, {"y", 1}, {"r", 2}},
			{{"x",2}, {"y", 0}, {"r", -1}},
			{{"x",4}, {"y", 2}, {"r", 2}}
	};

	int i = 0;
	for(auto c : cc) {
		i++;
		cout << "Tests case #" << i << " " << (calcTask3(c["x"], c["y"] == c["r"]) ? "Ok" : "Fail") << endl;
	}
}

void task3() {
//	test();

	int x, y;
	cin >> x >> y;
	if (y != 0) {
		cout << calcTask3(x, y);
	} else {
		cout << "Impossible";
	};
}
