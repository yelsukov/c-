#include <iostream>
#include <sstream>

using namespace std;

class Rational {
private:
	int numerator;
	int denominator;

	int findGreatesDelemiter(int a, int b) {
		return (b != 0) ? this->findGreatesDelemiter(b, a % b) : a;
	}

public:
  Rational() {
	  this->numerator = 0;
	  this->denominator = 1;
  };
  Rational(int numerator, int denominator) {
	  if (denominator == 0) {
		  throw invalid_argument("Invalid argument");
	  }
	  if (denominator < 0) {
		  denominator *= -1;
		  numerator *= -1;
	  }

	  int d = this->findGreatesDelemiter(abs(numerator), abs(denominator));
	  numerator /= d;
	  denominator /= d;

	  this->numerator = numerator;
	  this->denominator = denominator;
  };

  int Numerator() const {
	  return this->numerator;
  };
  int Denominator() const {
	  return denominator;
  };
};
Rational operator +(const Rational& l, const Rational& r) {
	int ln = l.Numerator(),
		rn = r.Numerator(),
		ld = l.Denominator(),
		rd = r.Denominator();

	return Rational(ln * rd + rn * ld, ld * rd);
}

Rational operator -(const Rational& l, const Rational& r) {
	int ln = l.Numerator(),
		rn = r.Numerator(),
		ld = l.Denominator(),
		rd = r.Denominator();

	return Rational(ln * rd - rn * ld, ld * rd);
}

Rational operator *(const Rational& l, const Rational& r) {
	int ln = l.Numerator(),
		rn = r.Numerator(),
		ld = l.Denominator(),
		rd = r.Denominator();

	return Rational(ln * rn, ld * rd);
}

Rational operator /(const Rational& l, const Rational& r) {
	if (r.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

ostream& operator <<(ostream& stream, const Rational& r) {
//	if (abs(r.Numerator()) == abs(r.Denominator())) {
//		stream << r.Numerator();
//	} else if (r.Numerator() != 0) {
		stream << r.Numerator() << "/" << r.Denominator();
//	} else {
//		stream << 0;
//	}

	return stream;
}

istream& operator >>(istream& stream, Rational& r) {
	if (stream.peek() == EOF) {
		return stream;
	}

	int a = 0, s = 0;
	stream >> a;
	stream.ignore(1);
	stream >> s;
	r = Rational(a,s);

	return stream;
}

bool operator ==(const Rational& l, const Rational& r) {
	return l.Numerator() == r.Numerator() && l.Denominator() == r.Denominator();
}

bool operator <(const Rational& l, const Rational& r) {
	int ln = l.Numerator(),
		rn = r.Numerator(),
		ld = l.Denominator(),
		rd = r.Denominator();
	return ln * rd < rn * ld;
}

int calc () {
	char cmd;
	Rational X, Y;

	try {
		cin >> X >> cmd >> Y;
		switch (cmd) {
		case '+':
			cout << (X + Y);
			break;
		case '-':
			cout << (X - Y);
			break;
		case '*':
			cout << (X * Y);
			break;
		case '/':
			cout << (X / Y);
		break;
		}
	} catch (invalid_argument& e) {
		cout << e.what() << endl;
	} catch (domain_error& e) {
		cout << e.what() << endl;
	}

	return 0;
}
