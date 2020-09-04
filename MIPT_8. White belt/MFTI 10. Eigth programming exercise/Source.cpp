#include <iostream>

using namespace std;

int main() {

	int a, b, num;

	cin >> a >> b;

	if (a > b) {
		num = b;
		while (num != 0) {
			if (a % b == 0) {
				cout << b;
				break;
			}
			else {
				num = a % b;
				a = b;
				b = num;
			}
		}
	}
	else if (a < b) {
		num = a;
		while (num != 0) {
			if (b % a == 0) {
				cout << a;
				break;
			}
			else {
				num = b % a;
				b = a;
				a = num;
			}
		}
	}
	else {
		cout << a;
	}

	return 0;
}