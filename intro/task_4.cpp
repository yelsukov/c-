#include <iostream>
#include <map>
#include <vector>

using namespace std;

double calc4(double price, double sumA, double sumB, double discontX, double discontY) {
	double discont = 0;
	if (price > sumB) {
		discont = discontY;
	} else if (price > sumA) {
		discont = discontX;
	}

	return price - (price * (discont / 100));
}

void testTask4() {
	vector<map<string, double>> cc  = {
		{{"n", 100}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 100}},
		{{"n", 120}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 114}},
		{{"n", 110}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 110}},
		{{"n", 90}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 90}},
		{{"n", 0}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 0}},
		{{"n", 130}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 117}},
		{{"n", 115}, {"a", 110}, {"b", 120}, {"x", 5}, {"y", 10}, {"r", 109.25}},
	};

	int i = 0;
	for(auto c : cc) {
		i++;
		cout << "Tests case #" << i << " " << (calc4(c["n"], c["a"], c["b"], c["x"], c["y"]) == c["r"] ? "OK" : "FAIL") << endl;
	}
}

int task4() {
//	tests();

	double price, sumA, sumB, discontX, discontY;
	cin >> price >> sumA >> sumB >> discontX >> discontY;

	cout << calc4(price, sumA, sumB, discontX, discontY);

	return 0;
}
