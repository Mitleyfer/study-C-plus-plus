#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void add_track(vector<string> & tracks, int stops_nums) {
	string stop;
	for (int i = 0; i < stops_nums; i++) {
		cin >> stop;
		tracks.push_back(stop);
	}
}

int main() {
	map<vector<string>, int> tracks;
	int q;
	int num = 0;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int stops_nums;
		vector<string> track;
		cin >> stops_nums;
		add_track(track, stops_nums);
		if (tracks.count(track) > 0) {
			cout << "Already exists for " << tracks[track] << endl;
		}
		else {
			num += 1;
			tracks[track] = num;
			cout << "New bus " << num << endl;
		}
	}
	
	return 0;
}