#include <iostream>
#include <map>

using namespace std;

template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& k) {
	if (m.count(k) == 0) {
		throw runtime_error("element not found");
	}

	return m[k];
}


