#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a, b, c;
	double D, x_1, x_2;

	cin >> a >> b >> c;

	if (a != 0 && b != 0 && c != 0) {
		D = b * b - 4 * a * c;
		if (D > 0) {
			x_1 = (-(b)+sqrt(D)) / (2 * a);
			x_2 = (-(b)-sqrt(D)) / (2 * a);
			cout << x_1 << " " << x_2 << endl;
		}
		else if (D == 0) {
			x_1 = -(b) / (2 * a);
			cout << x_1;
		}
		else if (D < 0) {
			cout << " ";
		}
	}
	else if (a == 0 && c == 0) {
		x_1 = 0;
		cout << x_1;
	}
	else if (a == 0 && b == 0) {
		cout << " ";
	}
	else if (a == 0) {
		x_1 = -(c) / b;
		cout << x_1;
	}
	else if (b == 0) {
		if ((a > 0 && c < 0) || (a < 0 && c > 0)) {
			x_1 = sqrt(-(c) / a);
			x_2 = -(sqrt(-(c) / a));
			cout << x_1 << " " << x_2 << endl;
		}
		else {
			cout << " ";
		}
	}
	else if (c == 0) {
		x_1 = 0;
		x_2 = -(b) / a;
		cout << x_1 << " " << x_2;
	}
	
	return 0;
}