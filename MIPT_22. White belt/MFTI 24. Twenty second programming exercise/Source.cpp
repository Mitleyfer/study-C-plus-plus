#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void new_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, string bus, int stop_count) {
	string stop;
	for (int i = 0; i < stop_count; i++) {
		cin >> stop;
		buses[bus].push_back(stop);
		stops[stop].push_back(bus);
	}
}

void buses_for_stop(map<string, vector<string>>& stops, string stop) {
	if (stops.count(stop) == 0) {
		cout << "No stop" << endl;
	}
	else {
		for (auto x : stops[stop]) {
			cout << x << " " << flush;
		}
		cout << endl;
	}
}

void stop_for_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, string bus) {
	if (buses.count(bus) == 0) {
		cout << "No bus" << endl;
	}
	else {
		for (auto x : buses[bus]) {
			for (auto y : stops) {
				if (x == y.first) {
					cout << "Stop " << x << ": " << flush;
					if (y.second.size() > 1) {
						for (auto z : y.second) {
							if (z == bus) {
								continue;
							}
							else {
								cout << z << " " << flush;
							}
						}
						cout << endl;
					}
					else {
						cout << "no interchange" << endl;
					}
				}
			}
		}
		cout << endl;
	}
}

void all_buses(const map<string, vector<string>>& buses) {
	if (buses.size() == 0) {
		cout << "No buses" << endl;
	}
	else {
		for (auto x : buses) {
			cout << "Bus " << x.first << ": " << flush;
			for (auto y : x.second) {
				cout << y << " " << flush;
			}
			cout << endl;
		}
	}
}

int main() {
	map<string, vector<string>> stops;
	map<string, vector<string>> buses;
	string operation;
	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> operation;
		if (operation == "NEW_BUS") {
			string bus;
			int stop_count;
			cin >> bus >> stop_count;
			new_bus(buses, stops, bus, stop_count);
		}
		else if (operation == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			buses_for_stop(stops, stop);
		}
		else if (operation == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			stop_for_bus(buses, stops, bus);
		}
		else if (operation == "ALL_BUSES") {
			all_buses(buses);
		}
	}

	return 0;
}