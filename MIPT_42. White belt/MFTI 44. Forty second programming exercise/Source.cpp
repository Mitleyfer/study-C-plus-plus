#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};
int main() {
	vector<student> students;
	int n, m, day, month, year, number;
	string first_name, last_name, request;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> first_name >> last_name >> day >> month >> year;
		students.push_back(student{ first_name, last_name, day, month, year });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> request >> number;
		if (request == "name" && (number <= students.size() && number > 0)) {
			cout << students[number - 1].first_name << " " << students[number - 1].last_name << endl;
		}
		else if (request == "date" && (number <= students.size() && number > 0)) {
			cout << students[number - 1].day << "." << students[number - 1].month << "." << students[number - 1].year << endl;
		}
		else {
			cout << "bad request" << endl;
		}
	}
	return 0;
}