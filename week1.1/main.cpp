#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main () {
	int N;
	cin >> N;
	if (N == 0) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> days(N);
	int64_t avg = 0;
	for(int& t : days) {
		cin >> t;
		avg += t;
	}

	avg /= N;

	int cnt = 0;
	stringstream out;
	for (uint i = 0; i < days.size(); ++i) {
		if (days[i] > avg) {
			cnt++;
			out << i << " ";
		}
	}

	cout << cnt << endl;
	cout << out.str();

	return 0;
}
