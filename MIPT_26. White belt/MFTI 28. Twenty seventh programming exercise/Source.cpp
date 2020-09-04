#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

void give_number(map<set<string>, int>& bus_numbers) {
	set<string> stops;
	int stops_nums;
	string stop;
	cin >> stops_nums;
	for (int i = 0; i < stops_nums; i++) {
		cin >> stop;
		stops.insert(stop);
	}
	if (bus_numbers.count(stops) == 0) {
		bus_numbers[stops] += bus_numbers.size();
		cout << "New bus " << bus_numbers[stops] + 1 << endl;
	}
	else {
		cout << "Already exists for " << bus_numbers[stops] + 1 << endl;
	}
}

int main() {
	map<set<string>, int> bus_numbers;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		give_number(bus_numbers);
	}
	return 0;
}