#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// a*x^2 + b*x + c = 0
void calcTask2(double a, double b, double c) {
	double D, x1, x2;

	if (a == 0) {
		if (b != 0) {
			cout << -c / b << endl;
		} else {
			cout << endl;
		}

		return;
	}

	D = pow(b, 2) - 4 * a * c;
	if (D > 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << " " << x2 << endl;
	} else if (D == 0) {
		cout << -b / (2 * a) << endl;
	} else {
		cout << endl;
	}
}
