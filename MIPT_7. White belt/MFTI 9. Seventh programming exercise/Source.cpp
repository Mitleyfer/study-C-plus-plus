#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int counter = 0;

	cin >> s;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == 'f') {
			counter += 1;
			if (counter == 2) {
				cout << i << endl;
			}
		}
	}
	if (counter == 1) {
		cout << -1 << endl;
	}
	else if (counter == 0) {
		cout << -2 << endl;
	}
}