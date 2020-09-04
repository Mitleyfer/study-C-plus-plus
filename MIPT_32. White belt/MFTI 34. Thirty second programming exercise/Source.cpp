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
	vector<string> Get_info(map<int, string> info, int year) {
		vector<string> result;
		for (const auto& x : info) {
			if (x.first > year) {
				break;
			}
			else {
				if (result.size() != 0) {
					if (result[0] == x.second) {
						continue;
					}
				}
				result.emplace(result.begin(), x.second);
			}	
		}
		return result;
	}
	string GetFullNameWithHistory(int year) {
		vector<string> history_of_names  = Get_info(names, year);
		vector<string> history_of_surnames = Get_info(surnames, year);
		string first_name = Get_name(names, year);
		string last_name = Get_name(surnames, year);
		string result;
		if (first_name.size() == 0 && last_name.size() == 0) {
			return "Incognito";
		}
		else if (first_name.size() == 0 && history_of_surnames.size() == 1) {
			result += last_name;
			result += " with unknown first name";
		}
		else if (last_name.size() == 0 && history_of_names.size() == 1) {
			result += first_name;
			result += " with unknown last name";
		}
		else if (first_name.size() == 0 && history_of_surnames.size() > 1) {
			if (last_name == history_of_surnames[0]) {
				result += last_name;
				result += " (";
				for (int i = 1; i < history_of_surnames.size() - 1; i++) {
					if (history_of_surnames[i] != history_of_surnames[history_of_surnames.size() - 1]) {
						result += history_of_surnames[i];
						result += ", ";
					}
				}
				result += history_of_surnames[history_of_surnames.size() - 1];
				result += ")";
				result += " with unknown first name";
			}
			else {
				result += last_name;
				for (int i = 1; i < history_of_surnames.size() - 1; i++) {
					if (history_of_surnames[i] != history_of_surnames[history_of_surnames.size() - 1]) {
						result += history_of_surnames[i];
						result += ", ";
					}
				}
				result += history_of_surnames[history_of_surnames.size() - 1];
				result += ")";
				result += " with unknown first name";
			}
		}
		else if (last_name.size() == 0 && history_of_names.size() > 1) {
			if (first_name == history_of_names[0]) {
				result += first_name;
				result += " (";
				for (int i = 1; i < history_of_names.size() - 1; i++) {
					if (history_of_names[i] != history_of_names[history_of_names.size() - 1]) {
						result += history_of_names[i];
						result += ", ";
					}
				}
				result += history_of_names[history_of_names.size() - 1];
				result += ")";
				result += " with unknown last name";
			}
			else {
				result += first_name;
				for (int i = 1; i < history_of_names.size() - 1; i++) {
					if (history_of_names[i] != history_of_names[history_of_names.size() - 1]) {
						result += history_of_names[i];
						result += ", ";
					}
				}
				result += history_of_names[history_of_names.size() - 1];
				result += ")";
				result += " with unknown first name";
			}
		}
		else if (history_of_names.size() == 1 && history_of_surnames.size() == 1) {
			result += first_name;
			result += " ";
			result += last_name;
		}
		else if (history_of_names.size() > 1 && history_of_surnames.size() == 1) {
			if (first_name == history_of_names[0]) {
				result += first_name;
				result += " (";
				for (int i = 1; i < history_of_names.size() - 1; i++) {
					if (history_of_names[i] != history_of_names[history_of_names.size() - 1]) {
						result += history_of_names[i];
						result += ", ";
					}
				}
				result += history_of_names[history_of_names.size() - 1];
				result += ")";
			}
			else {
				result += first_name;
				for (int i = 1; i < history_of_names.size() - 1; i++) {
					if (history_of_names[i] != history_of_names[history_of_names.size() - 1]) {
						result += history_of_names[i];
						result += ", ";
					}
				}
				result += history_of_names[history_of_names.size() - 1];
				result += ")";
			}
			result += " ";
			result += history_of_surnames[0];
		}
		else if (history_of_names.size() == 1 && history_of_surnames.size() > 1) {
			result += first_name;
			result += " ";
			if (last_name == history_of_surnames[0]) {
				result += last_name;
				result += " (";
				for (int i = 1; i < history_of_surnames.size() - 1; i++) {
					if (history_of_surnames[i] != history_of_surnames[history_of_surnames.size() - 1]) {
						result += history_of_surnames[i];
						result += ", ";
					}
				}
				result += history_of_surnames[history_of_surnames.size() - 1];
				result += ")";
			}
			else {
				result += last_name;
				for (int i = 1; i < history_of_surnames.size() - 1; i++) {
					if (history_of_surnames[i] != history_of_surnames[history_of_surnames.size() - 1]) {
						result += history_of_surnames[i];
						result += ", ";
					}
				}
				result += history_of_surnames[history_of_surnames.size() - 1];
				result += ")";
			}
		}
		else {
			if (first_name == history_of_names[0]) {
				result += first_name;
				result += " (";
				for (int i = 1; i < history_of_names.size() - 1; i++) {
					if (history_of_names[i] != history_of_names[history_of_names.size() - 1]) {
						result += history_of_names[i];
						result += ", ";
					}
				}
				result += history_of_names[history_of_names.size() - 1];
				result += ")";
			}
			else {
				result += first_name;
				for (int i = 1; i < history_of_names.size() - 1; i++) {
					if (history_of_names[i] != history_of_names[history_of_names.size() - 1]) {
						result += history_of_names[i];
						result += ", ";
					}
				}
				result += history_of_names[history_of_names.size() - 1];
				result += ")";
			}
			result += " ";
			if (last_name == history_of_surnames[0]) {
				result += last_name;
				result += " (";
				for (int i = 1; i < history_of_surnames.size() - 1; i++) {
					if (history_of_surnames[i] != history_of_surnames[history_of_surnames.size() - 1]) {
						result += history_of_surnames[i];
						result += ", ";
					}
				}
				result += history_of_surnames[history_of_surnames.size() - 1];
				result += ")";
			}
			else {
				result += last_name;
				result += "(";
				for (int i = 0; i < history_of_surnames.size() - 1; i++) {
					if (history_of_surnames[i] != history_of_surnames[history_of_surnames.size() - 1]) {
						result += history_of_surnames[i];
						result += ", ";
					}
				}
				result += history_of_surnames[history_of_surnames.size() - 1];
				result += ")";
			}
		}
		return result;
	}

private:
	map<int, string> names;
	map<int, string> surnames;
	string Get_name(map<int, string> data, int year) {
		string name;
		for (const auto x : data) {
			if (x.first > year) {
				break;
			}
			else {
				name = x.second;
			}
		}
		return name;
	}
};

int main() {
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;

	return 0;
}