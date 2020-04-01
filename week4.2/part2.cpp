#include <iostream>
#include <fstream>

using namespace std;

int main_part2main_week_4_task_1_2() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	if (input.is_open() && output.is_open()) {
		string line;
		while(getline(input, line)) {
			output << line << endl;
		}
	} else {
		cout << "Can not open file" << endl;
	}

	return 0;
}
