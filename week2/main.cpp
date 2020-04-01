#include <iostream>
#include <map>
#include <set>

using namespace std;

map<set<string>, uint> uRoutes;

void newUniqRoute() {
	uint qty;
	cin >> qty;

	set<string> route;
	for (uint i = 0; i < qty; i++) {
		string stop;
		cin >> stop;
		route.insert(stop);
	}

	if (uRoutes.count(route) == 0) {
		uint i = uRoutes.size() + 1;
		uRoutes[route] = i;
		cout << "New bus " << i << endl;
	} else {
		cout << "Already exists for " << uRoutes[route] << endl;
	}
}

int main() {
	uint qty;
	cin >> qty;

	set<string> route;
	while (qty != 0) {
		newUniqRoute();
		qty--;
	}
	return 0;
}
