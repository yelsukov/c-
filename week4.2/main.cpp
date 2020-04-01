#include <iostream>
#include <vector>

using namespace std;

struct Student {
public:
	string Name;
	string Lastname;
	uint BirthDay;
	uint BirthMonth;
	uint BirthYear;

	void PrintBirthDate() {
		cout << BirthDay << "." << BirthMonth << "." << BirthYear << endl;
	};

	void PrintName() {
		cout << Name << " " << Lastname << endl;
	};
};

int main() {
	uint N;
	cin >> N;
	vector<Student> students(N);

	for (auto& s : students) {
		cin >> s.Name >> s.Lastname >> s.BirthDay >> s.BirthMonth >> s.BirthYear;
	}

	uint M;
	cin >> M;
	while (M != 0) {
		M--;

		string cmd;
		uint id;
		cin >> cmd >> id;

		if (id == 0 || N <= (id - 1)) {
			cout << "bad request" << endl;
			continue;
		}
		id--;

		if (cmd == "name") {
			students[id].PrintName();
		} else if (cmd == "date") {
			students[id].PrintBirthDate();
		} else {
			cout << "bad request" << endl;
		}
	}

	return 0;
}
