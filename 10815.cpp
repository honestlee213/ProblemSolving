#include <iostream>
#include <map>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    map<int, int> album;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        
        album[card] = 1;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int card;
        cin >> card;
        
        cout << album[card];
        if (i < m - 1)
            cout << " ";
    }

    return 0;
}