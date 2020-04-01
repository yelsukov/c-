#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrom(string s) {
	uint size = s.size();
	if (size == 1) return false;
    for (size_t i = 0; i < size / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter (vector<string> words, int minLength) {
	vector<string> result;

	for(auto w : words) {
		if(w.size() >= minLength && IsPalindrom(w)) {
			result.push_back(w);
		}
	}

	return result;
}

void testsIsPalindrom() {
	vector<string> cc  = {
		"string",
		"",
		"madam",
		"argentinamanitnegra",
		"xox",
		"zzzz",
		"s",
		"ss"
	};

	vector<bool> rr = {
			false, // 1
			true, //  2
			true, // 3
			true, // 4
			true, // 5
			true, // 6
			false, // 7
			true
	};

	for (uint i = 0; i < cc.size(); ++i) {
		cout << "Tests case #" << i + 1 << " "<< (IsPalindrom(cc[i]) == rr[i] ? "OK" : "FAIL") << endl;
	}
}

void testPalindromFilter() {
	vector<vector<string>> cc = {
		{"abacaba", "aba"},
		{"abacaba", "aba"},
		{"weew", "bro", "code"},
		{},
		{},
		{"w", "", "zz"}
	};
	vector<int> ll = {
			5, 2, 4, 0, 1, 0
	};
	vector<vector<string>> rr = {
			{"abacaba"},
			{"abacaba", "aba"},
			{"weew"},
			{},
			{},
			{"", "zz"}
	};

	for (uint i = 0; i < cc.size(); ++i) {
		cout << "Tests case #" << i + 1 << " "<< (PalindromFilter(cc[i], ll[i]) == rr[i] ? "OK" : "FAIL") << endl;
	}
}

int main10() {
//	tests();
	testPalindromFilter();


	return 0;
}
