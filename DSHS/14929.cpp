#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    long long sum = 0;
    long long square_sum = 0;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        sum += (long long) m;
        square_sum += (long long) m * m;
    }

    cout << (sum * sum - square_sum) / (long long) 2;

    return 0;
}