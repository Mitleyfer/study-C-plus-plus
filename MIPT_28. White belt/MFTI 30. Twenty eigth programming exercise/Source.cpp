#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool modulo(int i, int j) {
	if (abs(i) != abs(j)) {
		return abs(i) < abs(j);
	}
	return (i < j);
}

int main() {
	vector<int> nums;
	int num, q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), modulo);
	cout << endl;
	for (auto x : nums) {
		cout << x << " " << flush;
	}
	return 0;
}