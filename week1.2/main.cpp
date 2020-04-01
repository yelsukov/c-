#include <iostream>

using namespace std;

int main () {
	uint N, R;
	cin >> N >> R;
	uint64_t sum = 0;
	for (uint i = 0; i < N; ++i) {
		uint16_t W, H, D;
		cin >> W >> H >> D;
		sum += (static_cast<uint64_t>(R) * W * H * D);
	}

	cout << sum << endl;
	return 0;
}
