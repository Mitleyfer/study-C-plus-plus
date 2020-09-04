#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		surnames[year] = last_name;
	}
	string GetFullName(int year) {
		string full_name = "";
		string first_name = "with unknown first name";
		string last_name = "with unknown last name";
		for (const auto& x : names) {
			if (x.first > year) {
				break;
			}
			else {
				first_name = x.second;
			}
		}
		for (const auto& y : surnames) {
			if (y.first > year) {
				break;
			}
			else {
				last_name = y.second;
			}
		}
		full_name = first_name + " " + last_name;
		if (full_name == "with unknown first name with unknown last name") {
			return "Incognito";
		}
		if (first_name == "with unknown first name") {
			full_name = last_name + " " + first_name;
		}
		return full_name;
		
	}

private:
	map<int, string> names;
	map<int, string> surnames;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	return 0;
}