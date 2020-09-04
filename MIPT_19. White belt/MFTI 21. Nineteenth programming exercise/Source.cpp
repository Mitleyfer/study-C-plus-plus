#include <iostream>
#include <vector>
#include <string>

using namespace std;

void add(vector<vector<string>>& v, int index, string action) {
	v[index - 1].push_back(action);
}

int main() {
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> list_of_duties;
	int Q;
	int index;
	int counter = 0;
	string command, action;
	
	list_of_duties.resize(months[0]);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> index >> action;
			add(list_of_duties, index, action);
		}
		else if (command == "DUMP") {
			cin >> index;
			cout << list_of_duties[index - 1].size() << flush;
			for (int i = 0; i < list_of_duties[index - 1].size(); i++) {
				cout << " " << list_of_duties[index - 1][i]<< " " << flush;
			}
			cout << endl;
		}
		else if (command == "NEXT") {
			counter += 1;
			if (counter <= 11) {
				if (months[counter] >= months[counter - 1]) {
					list_of_duties.resize(months[counter]);
				}
				else if (months[counter] < months[counter - 1]) {
					int diff;
					diff = months[counter - 1] - months[counter];
					for (int i = 0; i < diff; i++) {
						list_of_duties[months[counter] - 1].insert(end(list_of_duties[months[counter] - 1]), begin(list_of_duties[months[counter] + i]), end(list_of_duties[months[counter] + i]));
					}
					list_of_duties.resize(months[counter]);
				}
			}
			else {
				list_of_duties.resize(months[0]);
				counter = 0;
			}
		}
	}
	return 0;
}