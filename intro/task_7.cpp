#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search(string s) {
	int res = -2;
	int i = 0;
	for (char letter : s) {
		if (letter == 'f') {
			if (res == -1) {
				res = i;
				break;
			}
			res = -1;
		}
		i++;
	}

	return res;
}

void testTask7() {
	vector<string> cc  = {
		"comfort",
		"coffee",
		"car",
		"fyck off",
	};

	vector<int> rr = {
		-1,
		3,
		-2,
		6
	};

	for (uint i = 0; i < cc.size(); ++i) {
		cout << "Tests case #" << i+1 << " " << (search(cc[i]) == rr[i] ? "OK" : "FAIL") << endl;
	}
}

int task7() {
//	tests();
	string a;
	cin >> a;
	cout << search(a);

	return 0;
}
