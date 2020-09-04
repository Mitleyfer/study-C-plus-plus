#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
string str_to_low(const string& s) { 
    string result;
    for (auto i : s) { 
        result += tolower(i); 
    }
    return result; 
}
bool srt(string x, string y) {
    return str_to_low(x) < str_to_low(y); 
}
int main() {
    int n;
    string str;
    vector<string> v; 
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> str; 
        v.push_back(str); 
    }
    
    sort(begin(v), end(v), srt);
    for (const auto& i : v) {
        cout << i << " ";
    }
    return 0;
}