#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int idx = 0;
    int n = 0;

    getline(cin, s);
    
    while (s.length() != idx) {
        if (s.find(" ", idx) != string::npos && idx != s.find(" ", idx)) {
            int pos = s.find(" ", idx);
            // cout << s.substr(idx, pos - idx) << endl;
            idx = pos;
            n++;
        } else if (s.find(" ", idx) == string::npos && idx != s.length()) {
            // cout << s.substr(idx) << endl;
            n++;
            idx = s.length();
        } else {
            idx++;
        }
    }

    cout << n << endl;

    return 0;
}