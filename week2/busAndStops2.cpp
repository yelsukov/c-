#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<vector<string>, uint> Routes;

void newBus() {
	uint qty;
	cin >> qty;

	vector<string> route(qty);
	for(string& stop : route) {
		cin >> stop;
	}

	if (Routes.count(route) == 0) {
		uint i = Routes.size() + 1;
		Routes[route] = i;
		cout << "New bus " << i << endl;
	} else {
		cout << "Already exists for " << Routes[route] << endl;
	}
}

int main_bs_2() {
	uint qty;
	cin >> qty;

	vector<string> route;
	while (qty != 0) {
		newBus();
		qty--;
	}
	return 0;
}
