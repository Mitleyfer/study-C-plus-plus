#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void add(map<string, int>& words, set<set<string>>& pairs, string word_1, string word_2) {
	set<string> pair;
	pair.insert(word_1);
	pair.insert(word_2);
	if (pairs.count(pair) == 0) {
		pairs.insert(pair);
		words[word_1] += 1;
		words[word_2] += 1;
	}
}

void count(map<string, int>& words, string word) {
	cout << words[word] << endl;
}
void check(const set<set<string>>& pairs, string word_1, string word_2) {
	set<string> check;
	check.insert(word_1);
	check.insert(word_2);
	if (pairs.count(check) > 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	map<string, int> words;
	set<set<string>> pairs;
	string operation, word_1, word_2;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> operation;
		if (operation == "ADD") {
			cin >> word_1 >> word_2;
			add(words, pairs, word_1, word_2);
		}
		else if (operation == "COUNT") {
			cin >> word_1;
			count(words, word_1);
		}
		else if (operation == "CHECK") {
			cin >> word_1 >> word_2;
			check(pairs, word_1, word_2);
		}
	}
	
	return 0;
}