#include <iostream>
#include <map>

using namespace std;

map<string, string> countries;

void setCapital(string country, string capital) {
	bool isNew = countries.count(country) == 0;
	if (!isNew && countries[country] == capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
		return;
	}

	string oldCapital = countries[country];
	countries[country] = capital;

	if(isNew) {
		cout << "Introduce new country " << country << " with capital " << capital << endl;
	} else {
		cout << "Country " << country << " has changed its capital from " << oldCapital << " to " << capital << endl;
	}
}

void rename(string country, string name) {
	if (country == name || countries.count(country) == 0 || countries.count(name) == 1) {
		cout << "Incorrect rename, skip" << endl;
		return;
	}

	countries[name] = countries[country];
	countries.erase(country);

    cout << "Country " << country << " with capital " << countries[name] << " has been renamed to " << name << endl;
}

void about(string country) {
	if (countries.count(country) == 0) {
		cout << "Country " << country << " doesn't exist" << endl;
		return;
	}
	cout << "Country " << country << " has capital " << countries[country] << endl;
}

void dump () {
	if (countries.size() == 0) {
		cout << "There are no countries in the world" << endl;
		return;
	}

	for (auto c : countries) {
		cout << c.first << "/" << c.second << " ";
	}
	cout << endl;
}

int coutries () {
	uint qty;
	cin >> qty;

	while (qty != 0) {
		string cmd, country;
		cin >> cmd;

		if (cmd == "CHANGE_CAPITAL") {
			string capital;
			cin >> country >> capital;
			setCapital(country, capital);
		} else if (cmd == "RENAME") {
			string name;
			cin >> country >> name;
			rename(country, name);
		} else if (cmd == "ABOUT") {
			cin >> country;
			about(country);
		} else if (cmd == "DUMP") {
			dump();
		} else {
			cout << "Unrecognized command" << endl;
			continue;
		}
		qty--;
	}

	return 0;
}



