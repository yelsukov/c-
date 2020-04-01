#include <iostream>
#include <set>

using namespace std;

int main_cus () {
	uint qty;
	set<string> uniq;

	cin >> qty;
	for (uint i = 0; i < qty; i++) {
		string s;
		cin >> s;
		uniq.insert(s);
	}

	cout << uniq.size();

	return 0;
}
