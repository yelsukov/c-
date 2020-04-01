#include <iostream>
#include <fstream>

using namespace std;

int main_week_4_task_1_1() {
	ifstream fileStream("input.txt");
	if (fileStream.is_open()) {
		string line;
		while(getline(fileStream, line)) {
			cout << line << endl;
		}
	} else {
		cout << "Can not open file" << endl;
	}

	return 0;
}
