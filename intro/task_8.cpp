#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

string calc8(int n) {
	vector<string> vr;
	do {
		vr.push_back((n % 2 == 0 ? "0" : "1"));
		n /= 2;
	} while (n != 0);

	string r = "";
	while (vr.size() != 0) {
		r += vr.back();
		vr.pop_back();
	}

	return r;
}

void tests8() {
	vector<int> cc  = {
		5,
		10,
		1010,
		32,
		1,
		0,
		256,
		1001000,
	};
	vector<string> rr = {
		"101",
		"1010",
		"1111110010",
		"100000",
		"1",
		"0",
		"100000000",
		"11110100011000101000",
	};

	for (uint i = 0; i < cc.size(); i++) {
		cout << "Tests case #" << i+1<< " "<< (calc8(cc[i]) == rr[i] ? "OK" : "FAIL") << endl;
	}
}

int task8() {
//	tests();
	int n;
	cin >> n;
	cout << calc8(n);

	return 0;
}
