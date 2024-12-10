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

    map<int, vector<int> > table;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        if (table.find(a) == table.end()) {
            vector<int> y;
            y.push_back(b);
            table[a] = y;
        } else {
            table[a].push_back(b);
        }
    }

    for (auto it : table) {
        sort(it.second.begin(), it.second.end());
        for (auto y : it.second) {
            cout << it.first << " " << y << "\n";
        }
    }

    return 0;
}