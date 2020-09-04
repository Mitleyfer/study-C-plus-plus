#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v) {
	vector<int> reversed;
	for (int i = v.size() - 1; i >= 0; i--) {
		reversed.push_back(v[i]);
	}
	v = reversed;
}

int main() {
	vector<int> v = { 1, 2, 3, 4, 5 };

	Reverse(v);

	for (auto x : v) {
		cout << x << " " << flush;
	}

	return 0;
}