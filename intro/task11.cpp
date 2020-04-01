#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void UpdateIfGreater(const int& first, int& second) {
	if (first > second) {
		second = first;
	}
}

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for(uint i = 0; i < source.size(); i++) {
		destination.push_back(source[i]);
	}
	source.clear();
}

void testsUpdateIfGreater() {
	vector<vector<int>> cc  = {
			{0, 1, 1},
			{4, 2, 4},
			{3, 3, 3},
			{4, 0, 4}
	};

	uint i = 1;
	for (auto c : cc) {
		UpdateIfGreater(c[0], c[1]);
		cout << "Tests case #" << i << " "<< (c[1] == c[2] ? "OK" : "FAIL") << endl;
		i++;
	}
}

void Reverse(vector<int>& v) {
	reverse(v.begin(), v.end());
}

vector<int> Reversed(const vector<int>& v) {
	vector<int> res = v;
	Reverse(res);
	return res;
}

void PrintVector(vector<string> v) {
	for (auto s : v) {
		cout << s << " ";
	}
	cout << endl;
}

void PrintIntVector(vector<int> v) {
	for (auto s : v) {
		cout << s << " ";
	}
	cout << endl;
}

int main11() {
//	testsUpdateIfGreater();
//	vector<string> source = {"a", "b", "c"};
//	vector<string> destination = {"z"};
//	MoveStrings(source, destination);
//	cout << source.size() << " ";
//	cout << endl;
//	PrintVector(destination);
//	cout << endl;
//
//	vector<int> numbers = {1, 5, 3, 4, 2};
//	Reverse(numbers);
//	PrintIntVector(numbers);

	vector<int> z(0);
	cout << z.size() << endl;
//	z.resize(0);

	z.push_back(0);
	z[1] = 2;
	z[2] = 3;
	cout << z.size() << endl;
	z.resize(0);
	cout << z.size() << endl;
	return 0;
}
