#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void come(int k, vector<bool>& v) {
	if (k > 0) {
		for (int i = 0; i < k; i++) {
			v.push_back(false);
		}
	}
	else if (k < 0) {
		v.resize(v.size() + k);
	}
}

void worry(int i, vector<bool>& v) {
	v[i] = true;
}

void quiet(int i, vector<bool>& v) {
	v[i] = false;
}

int worry_count(vector<bool> v) {
	int counter = 0;
	for (auto x : v) {
		if (x == true) {
			counter += 1;
		}
	}
	return counter;
}

int main() {
	vector<bool> crowd;
	vector<int> results;
	string operation;
	int quantity;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> operation;
		if (operation == "WORRY_COUNT") {
			results.push_back(count(crowd.begin(), crowd.end(), true));
		}
		else if (operation == "WORRY") {
			cin >> quantity;
			worry(quantity, crowd);
		}
		else if (operation == "QUIET") {
			cin >> quantity;
			quiet(quantity, crowd);
		}
		else if (operation == "COME") {
			cin >> quantity;
			come(quantity, crowd);
		}
	}
	for (auto x : results) {
		cout << x << endl;
	}

	return 0;
}