#include <iostream>
#include <string>
#include <map>

using namespace std;

void dump(map<string, string> countries) {
	if (countries.size() != 0) {
		for (auto x : countries) {
			cout << x.first << "/" << x.second << " " << flush;
		}
		cout << endl;
	}
	else {
		cout << "There are no countries in the world" << endl;
	}
}

void change_capital(map<string, string>& countries, string country, string new_capital) {
	if (countries[country] == "") {
		countries[country] = new_capital;
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	}
	else if (countries[country] == new_capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
	}
	else {
		cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
		countries[country] = new_capital;
	}
	
}

void rename(map<string, string>& countries, string old_country_name, string new_country_name) {
	if (countries.count(old_country_name) == 0) {
	cout << "Incorrect rename, skip" << endl;
	}
	else if (old_country_name == new_country_name) {
		cout << "Incorrect rename, skip" << endl;
	}
	else if (countries.count(new_country_name) > 0) {
		cout << "Incorrect rename, skip" << endl;
	}
	else {
		cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
		for (auto x : countries) {
			if (x.first == old_country_name) {
				string capital = x.second;
				countries.erase(x.first);
				countries[new_country_name] = capital;
				break;
			}
		}
	}
}

void about(map<string, string> countries, string country) {
	if (countries.count(country) > 0) {
		cout << "Country " << country << " has capital " << countries[country] << endl;
	}
	else {
		cout << "Country " << country << " doesn't exist" << endl;
	}
}

int main() {
	map<string, string> countries;
	string command;
	string country_name;
	string capital;
	string new_country_name;
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "CHANGE_CAPITAL") {
			cin >> country_name >> capital;
			change_capital(countries, country_name, capital);
		}
		else if (command == "RENAME") {
			cin >> country_name >> new_country_name;
			rename(countries, country_name, new_country_name);
		}
		else if (command == "ABOUT") {
			cin >> country_name;
			about(countries, country_name);
		}
		else if (command == "DUMP") {
			dump(countries);
		}
	}

	return 0;
}