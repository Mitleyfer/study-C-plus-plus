#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto x : source) {
		destination.push_back(x);
	}
	source.clear();
}

int main() {
	vector<string> s = { "aa", "bb", "cc" };
	vector<string> d = { "dd" };

	MoveStrings(s, d);

	for (auto x : d) {
		cout << x << " " << flush;
	}
	
	cout << endl;
	cout << s.size() << endl;

	return 0;
}