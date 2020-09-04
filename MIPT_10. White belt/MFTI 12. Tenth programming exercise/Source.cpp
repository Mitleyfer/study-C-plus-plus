#include <iostream>

using namespace std;

int Factorial(int x) {
	int result = 1;
	if (x > 0) {
		for (int i = 1; i <= x; i++) {
			result *= i;
		}
		return result;
	}
	else {
		return 1;
	}
}

int main() {

	int x;

	cin >> x;
	cout << Factorial(x);

	return 0;
}