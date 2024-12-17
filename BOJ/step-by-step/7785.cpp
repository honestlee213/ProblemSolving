#include <iostream>
#include <string>
#include <map>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int, greater<string> > timecard;

    for (int i = 0; i < n; i++) {
        string name, change;
        cin >> name >> change;

        if (change.compare("enter") == 0)
            timecard[name] = 1;
        else
            timecard.erase(name);
    }

    for (auto it : timecard)
        cout << it.first << "\n";

    return 0;
}