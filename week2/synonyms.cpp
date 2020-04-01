#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, set<string>> synonyms;

void add(const string& w1, const string& w2) {
	synonyms[w1].insert(w2);
	synonyms[w2].insert(w1);
}

void count(const string& w1) {
	cout << synonyms[w1].size() << endl;
}

void check(const string& w1, const string& w2) {
	cout << (synonyms.count(w1) == 1 && synonyms[w1].count(w2) == 1 ? "YES" : "NO") << endl;
}

int main_syn () {
	uint q;
	cin >> q;
	while (q != 0) {
		string cmd, word1;
		cin >> cmd >> word1 ;
		if (cmd == "ADD") {
			string word2;
			cin >> word2;
			add(word1, word2);
		} else if (cmd == "COUNT") {
			count(word1);
		} else if (cmd == "CHECK") {
			string word2;
			cin >> word2;
			check(word1, word2);
		} else {
			cout << "Unrecognized command" << endl;
			continue;
		}
		q--;
	}
	return 0;
}
