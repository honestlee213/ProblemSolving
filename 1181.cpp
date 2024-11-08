#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, vector<string> > table;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int len = str.length();
        
        if (table.find(len) == table.end()) {
            vector<string> same_len;
            same_len.push_back(str);
            table[len] = same_len;
        } else {
            table[len].push_back(str);
        }
    }

    for (auto it : table) {
        sort(it.second.begin(), it.second.end());
        for (int i = 0; i < it.second.size(); i++)
            if (i == 0 || it.second[i].compare(it.second[i - 1]) != 0)
                cout << it.second[i] << "\n";
    }

    return 0;
}