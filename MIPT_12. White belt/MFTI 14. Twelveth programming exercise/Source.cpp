#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s) {
	for (int i = 0; i <= s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
	for (auto x : words) {
		if (IsPalindrom(x) == true && x.size() >= minLength) {
			result.push_back(x);
		}
	}
	for (auto x : result) {
		cout << x << " " << flush;
	}
	cout << endl;
	return result;
}


int main() {
	vector<string> a = { "abacaba", "aba" };
	vector<string> b = { "abacaba", "aba" };
	vector<string> c = { "weew", "bro", "code" };

	PalindromFilter(a, 5);
	PalindromFilter(b, 2);
	PalindromFilter(c, 4);

	return 0;
}
