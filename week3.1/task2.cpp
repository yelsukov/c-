#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_task2() {
	uint qty;
	cin >> qty;
	vector<string> v(qty);
	for(string& i : v) {
		cin >> i;
	}

	sort(v.begin(), v.end(), [](string x, string y) {
		string lowerX = x, lowerY = y;
		transform(lowerX.begin(), lowerX.end(), lowerX.begin(), ::tolower);
		transform(lowerY.begin(), lowerY.end(), lowerY.begin(), ::tolower);
		return lowerX < lowerY;
	});

	for(const string& i : v) {
		cout << i << " ";
	}

	return 0;
}
