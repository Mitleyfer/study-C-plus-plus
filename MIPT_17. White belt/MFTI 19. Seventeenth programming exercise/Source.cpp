#include <iostream>
#include <vector>

using namespace std;

double mean(vector<double> v) {
	double sum = 0;
	for (auto x : v) {
		sum += x;
	}
	return sum / v.size();
}

int main() {
	vector<double> v;
	int n;
	int count = 0;
	double temperature;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temperature;
		v.push_back(temperature);
	}
	double m = mean(v);
	for (auto x : v) {
		if (x > m) {
			count += 1;
		}
	}
	cout << count << endl;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > m) {
			cout << i << " " << flush;
		}
	}
}