#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int num[100] = {0,};
    int max = 0;
    int max_idx = 0;

    cin >> s;
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch >= 'A' && ch <= 'Z')
            num[ch] = num[ch] + 1;
        else if (ch >= 'a' && ch <= 'z')
            num[ch - ('a' - 'A')] = num[ch - ('a' - 'A')] + 1;
    }

    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
        if (num[i] > max) {
            max = num[i];
            max_idx = i;
        } else if (num[i] == max && max != 0) {
            max_idx = '?';
        }
    }

    cout << (char)max_idx << endl;

    return 0;
}