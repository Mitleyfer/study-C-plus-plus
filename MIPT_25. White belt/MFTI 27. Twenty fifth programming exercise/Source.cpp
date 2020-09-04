#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> result;
	for (auto x : m) {
		result.insert(x.second);
	}
	return result;
}

int main() {
	map<int, string> m = { {1, "odd"}, {2, "even"}, {3, "odd"}, {4, "even"} };
	set<string> s = BuildMapValuesSet(m);
	for (auto x : s) {
		cout << x << endl;
	}
}