#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, result, div = 2;
	vector<int> v = {};

	cin >> n;

	while (n != 0) {
		if (n % div == 1) {
			v.push_back(1);
			n /= div;
		}
		else {
			v.push_back(0);
			n /= div;
		}
	}

	for (int i = (v.size() - 1); i >= 0; i--) {
		if (v[i] == 0) {
			v.erase(v.begin() + i);
		}
		else {
			break;
		}
	}

	for (int i = (v.size() - 1); i >= 0; i--) {
		
		cout << v[i] << flush;
	}

	return 0;
}