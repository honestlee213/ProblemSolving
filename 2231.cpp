#include <iostream>
#include <vector>
using namespace std;

// int compute_next(int n) {
//     int m = n;
//     int sum = n;
//     int cnt = 0;

//     while (m > 0) {
//         m = m / 10;
//         cnt++;
//     }
// }

int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int ans = 0;

    cin >> n;

    for (int m = 1; m < n; m++) {
        if (m < 10) {
            if (m + m == n) {
                ans = m;
                break;
            }
        }
        else if (m < 100) {
            if (m + m / 10 + m % 10 == n) {
                ans = m;
                break;
            }
        }
        else if (m < 1000) {
            if (m + m / 100 + (m % 100) / 10 + m % 10 == n) {
                ans = m;
                break;
            }
        }
        else if (m < 10000) {
            if (m + m / 1000 + (m % 1000) / 100 + (m % 100) / 10 + m % 10 == n) {
                ans = m;
                break;
            }
        }
        else if (m < 100000) {
            if (m + m / 10000 + (m % 10000) / 1000 + (m % 1000) / 100 + (m % 100) / 10 + m % 10 == n) {
                ans = m;
                break;
            }
        }
        else if (m < 1000000) {
            if (m + m / 100000 + (m % 100000) / 10000 + (m % 10000) / 1000 + (m % 1000) / 100 + (m % 100) / 10 + m % 10 == n) {
                ans = m;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}