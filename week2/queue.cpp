//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
//const uint STATE_QUIET = 0;
//const uint STATE_WORRIED = 1;
//
//const uint CMD_COME = 0;
//const uint CMD_WORRY = 1;
//const uint CMD_QUIET = 2;
//const uint CMD_COUNT = 3;
//
//map<string, uint> opMapping = {
//	{"COME", CMD_COME},
//	{"WORRY", CMD_WORRY},
//	{"QUIET", CMD_QUIET},
//	{"WORRY_COUNT", CMD_COUNT},
//};
//
//void setState(vector<uint>& queue, uint n, uint state) {
//	if (n >= queue.size()) {
//		return;
//	}
//
//	queue[n] = state;
//}
//
//void resizeQueue(vector<uint>& queue, int k) {
//	queue.resize(queue.size() + k, STATE_QUIET);
//}
//
//uint countWorried(const vector<uint>& queue) {
//	return count(queue.begin(), queue.end(), STATE_WORRIED);
//}
//
//int Queue() {
//	vector<uint> queue;
//	uint qty;
//
//	cin >> qty;
//
//	for(uint i = 0; i < qty; i++) {
//		int mod;
//		string cmdName;
//		cin >> cmdName;
//
//		if (opMapping.count(cmdName) == 0) {
//			cout << "Invalid command " << cmdName;
//			break;
//		}
//
//		if (opMapping[cmdName] != CMD_COUNT) {
//			cin >> mod;
//		}
//
//		switch(opMapping[cmdName]) {
//		case CMD_COME:
//			resizeQueue(queue, mod);
//			break;
//		case CMD_WORRY:
//			setState(queue, mod, STATE_WORRIED);
//			break;
//		case CMD_QUIET:
//			setState(queue, mod, CMD_QUIET);
//			break;
//		case CMD_COUNT:
//			cout << countWorried(queue) << endl;
//			break;
//		}
//	}
//
//	return 0;
//}
