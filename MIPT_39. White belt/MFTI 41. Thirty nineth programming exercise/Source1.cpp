#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	string line;
	while (getline(input, line)) {
		output << line << endl;
		cout << line << endl;
	}
	return 0;
}