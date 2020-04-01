#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main_task1() {
	uint qty;
	cin >> qty;
	vector<int> v(qty);
	for(auto&i : v) {
		cin >> i;
	}

	sort(v.begin(), v.end(), [](int x, int y) { return abs(x) < abs(y);});

	for(const auto& i : v) {
		cout << i << " ";
	}

	return 0;
}
