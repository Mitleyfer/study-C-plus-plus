#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(string s) {
	map<char, int> result;
	for (auto x : s) {
		++result[x];
	}
	return result;
}

int main() {
	int Q;
	string s_1;
	string s_2;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> s_1 >> s_2;
		map<char, int> dict_1 = BuildCharCounters(s_1);
		map<char, int> dict_2 = BuildCharCounters(s_2);
		if (dict_1 == dict_2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}