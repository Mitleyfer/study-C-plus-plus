#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Incognizable
{
private:
	vector<int> s;
public:
	Incognizable() {}
	Incognizable(int a) {
		s.push_back(a);
	}
	Incognizable(int a, int b) {
		s.push_back(a);
		s.push_back(b);
	}
};

int main()
{
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}