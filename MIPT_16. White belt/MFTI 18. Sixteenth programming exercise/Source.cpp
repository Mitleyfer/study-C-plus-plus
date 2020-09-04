#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> reversed;
	for (int i = v.size() - 1; i >= 0; i--) {
		reversed.push_back(v[i]);
	}
	return reversed;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	vector<int> r;

	r = Reversed(v);

	for (auto x : r) {
		cout << x << " " << flush;
	}

	return 0;
}