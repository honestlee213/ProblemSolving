#include <iostream>
#include <string>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    string big;
    int birth = 20000303;   // divisor
    int rm = 0;

    cin >> big;

    if (big.length() < 8) {
        cout << big;
        return 0;
    } else
        rm = stoi(big.substr(0, 7));

    for (int cnt = 7; cnt < big.length(); cnt++) {
        int dividend = rm * 10 + (big[cnt] - '0');
        rm = dividend % birth;
    }

    cout << rm;

    return 0;
}