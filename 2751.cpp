#include <iostream>
// #include <vector>
#include <algorithm>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // vector<int> num(n);
    int num[n];

    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);

    for (int i = 0; i < n; i++)
        cout << num[i] << '\n';

    return 0;
}