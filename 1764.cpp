#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, int> people;
    map<string, int> stranger;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        people[name] = 1;
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        
        if (people[name] == 1)
            stranger[name] = 1;
    }

    cout << stranger.size() << "\n";
    for (auto it : stranger)
        cout << it.first << "\n";

    return 0;
}