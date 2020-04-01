#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
	FunctionPart(const char o, const double v) {
		this->operation = o;
		this->value = v;
	}

	double Apply(const double v) const {
		double result = 0;
		switch (this->operation) {
		case '+':
			result =  v + this->value;
			break;
		case '-':
			result = v - this->value;
			break;
		case '*':
			result = v * this->value;
			break;
		case '/':
			result = v / this->value;
		}

		return result;
	}

	void Invert() {
		switch (this->operation) {
		case '+':
			this->operation = '-';
			break;
		case '-':
			this->operation = '+';
			break;
		case '*':
			this->operation = '/';
			break;
		case '/':
			this->operation = '*';
		}
	}

private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(const char o, const double v) {
		this->parts.push_back({o, v});
	}
	void Invert() {
		for(auto& p : this->parts) {
			p.Invert();
		}
		reverse(begin(this->parts), end(this->parts));
	}
	double Apply(double v) const {
		for(auto& p : this->parts) {
			v = p.Apply(v);
		}
		return v;
	}
private:
	vector<FunctionPart> parts;
};
