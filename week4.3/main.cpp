#include <iostream>
#include <map>
#include <set>
#include <vector>
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
		  denominator = 1;
	  } else if (denominator < 0) {
		  denominator *= -1;
		  numerator *= -1;
	  }

	  int d = this->findGreatesDelemiter(numerator, denominator);
	  if (d > 1) {
		  numerator /= d;
		  denominator /= d;
	  }

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
	int ln = l.Numerator(),
		rn = r.Numerator(),
		ld = l.Denominator(),
		rd = r.Denominator();

	return Rational(ln * rd, ld * rn);
}

ostream& operator <<(ostream& stream, const Rational& r) {
	stream << r.Numerator() << "/" << r.Denominator();
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

int main() {
	{
		const Rational r(-3, -10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(-3, -10) != 3/10" << endl;
			return 1;
		}
	}
	{
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
        	cout << r.Numerator() << " " << r.Denominator() << endl;
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
        	cout << r.Numerator() << " " << r.Denominator() << endl;
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    {
            Rational r1(4, 6);
            Rational r2(2, 3);
            bool equal = r1 == r2;
            if (!equal) {
                cout << "4/6 != 2/3" << endl;
                return 1;
            }
        }

        {
            Rational a(2, 3);
            Rational b(4, 3);
            Rational c = a + b;
            bool equal = c == Rational(2, 1);
            if (!equal) {
                cout << "2/3 + 4/3 != 2" << endl;
                return 2;
            }
        }

        {
            Rational a(5, 7);
            Rational b(2, 9);
            Rational c = a - b;
            bool equal = c == Rational(31, 63);
            if (!equal) {
                cout << "5/7 - 2/9 != 31/63" << endl;
                return 3;
            }
        }

        {
                Rational a(2, 3);
                Rational b(4, 3);
                Rational c = a * b;
                bool equal = c == Rational(8, 9);
                if (!equal) {
                    cout << "2/3 * 4/3 != 8/9" << endl;
                    return 1;
                }
            }

            {
                Rational a(5, 4);
                Rational b(15, 8);
                Rational c = a / b;
                bool equal = c == Rational(2, 3);
                if (!equal) {
                    cout << "5/4 / 15/8 != 2/3" << endl;
                    return 2;
                }
            }

            {
                    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
                    if (rs.size() != 3) {
                        cout << "Wrong amount of items in the set" << endl;
                        return 1;
                    }

                    vector<Rational> v;
                    for (auto x : rs) {
                        v.push_back(x);
                    }
                    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
                        cout << "Rationals comparison works incorrectly" << endl;
                        return 2;
                    }
                }

                {
                    map<Rational, int> count;
                    ++count[{1, 2}];
                    ++count[{1, 2}];

                    ++count[{2, 3}];

                    if (count.size() != 2) {
                        cout << "Wrong amount of items in the map" << endl;
                        return 3;
                    }
                }

                {
                       ostringstream output;
                       output << Rational(-6, 8);
                       if (output.str() != "-3/4") {
                           cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
                           return 1;
                       }
                   }
                   {
                       istringstream input("5/7");
                       Rational r;
                       input >> r;
                       bool equal = r == Rational(5, 7);
                       if (!equal) {
                           cout << "5/7 is incorrectly read as " << r << endl;
                           return 2;
                       }
                   }
                   {
                       istringstream input("5/7 10/8");
                       Rational r1, r2;
                       input >> r1 >> r2;
                       bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
                       if (!correct) {
                           cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
                           return 3;
                       }
                       input >> r1;
                       input >> r2;
                       correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
                       if (!correct) {
                           cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
                           return 4;
                       }
                   }


    cout << "OK" << endl;
    return 0;
}

