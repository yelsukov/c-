#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


vector<uint> AvgTemp(const vector<uint>& days) {
	vector<uint> res;
	float avg = accumulate(days.begin(), days.end(), 0.0) / days.size();
	for (uint i = 0; i < days.size(); i++) {
		if (days[i] > avg) {
			res.push_back(i);
		}
	}

	return res;
}

int main() {
	uint n;
	cin >> n;

	if (n == 0) {
		return 0;
	}

	vector<uint> dd(n);
	for (auto &d : dd) {
		cin >> d;
	}

	vector<uint> rr = AvgTemp(dd);
	cout << rr.size() << endl;

	for(auto t : rr) {
		cout << t << " ";
	}

	return 0;
}
