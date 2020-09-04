#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string s) {
	int limit = s.size() / 2;
	int start = 0;
	int end = s.size() - 1;

	while (limit != 0) {
		if (s[start] != s[end]) {
			return false;
		}
		start += 1;
		end -= 1;
		limit -= 1;
	}
	return true;
}

int main() {
	string s;

	cin >> s;
	cout << IsPalindrom(s);

	return 0;
}