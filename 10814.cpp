#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, vector<string> > table;

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        
        if (table.find(age) == table.end()) {
            vector<string> same_age;
            same_age.push_back(name);
            table[age] = same_age;
        } else {
            table[age].push_back(name);
        }
    }

    for (auto it : table)
        for (auto name : it.second)
            cout << it.first << " " << name << "\n";

    return 0;
}