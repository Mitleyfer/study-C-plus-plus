#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	set<string> unique;
	string input;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> input;
		unique.insert(input);
	}
	cout << unique.size() << endl;

	return 0;
}