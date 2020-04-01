#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
	ReversibleString() {};
	ReversibleString (const string& d) {
		this->data = d;
	}

	string ToString() const {
		return this->data;
	}

	void Reverse() {
		reverse(this->data.begin(), this->data.end());
	}
private:
	string data;
};

