#include <iostream>
#include <map>

using namespace std;

map<char, uint> BuildCharCounters(string word) {
	map<char, uint> result;
	for (char w : word) {
		result[w]++;
	}

	return result;
}

bool isAnagramm(string w1, string w2) {
	if (w1.size() != w2.size()) {
		return false;
	}

	return BuildCharCounters(w1) == BuildCharCounters(w2);
}

void testIsAnagramm() {
	cout << "Test #1 is " << (isAnagramm("tea", "eat") == true ? "OK" : "FAIL") << endl;
	cout << "Test #1 is " << (isAnagramm("sea", "eat") == false ? "OK" : "FAIL") << endl;
	cout << "Test #1 is " << (isAnagramm("tear", "eat") == false ? "OK" : "FAIL") << endl;
}

int anagramms() {
//	testIsAnagramm();

	uint qty;
	cin >> qty;

	string word1, word2;
	while (qty != 0) {
		cin >> word1 >> word2;
		cout << (isAnagramm(word1, word2) ? "YES" : "NO") << endl;
		qty--;
	}

	return 0;
}
