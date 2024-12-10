#include <iostream>
#include <vector>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pos(10000001);
    vector<int> neg(10000000);
    int n, m;
    int num;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num >= 0)
            pos[num] = pos[num] + 1;
        else
            neg[-1 * num] = neg[-1 * num] + 1;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        if (num >= 0)
            cout << pos[num];
        else
            cout << neg[-1 * num];
        if (i < m - 1)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}