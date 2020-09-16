#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	ifstream input("input.txt");
	string line;
	while (getline(input, line)) {
		cout << fixed << setprecision(3);
		cout << stod(line) << endl;
	}
	return 0;
}
