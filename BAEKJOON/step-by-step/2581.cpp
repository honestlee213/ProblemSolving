#include <iostream>
using namespace std;

bool is_prime(int a) {
    for (int i = 2; i <= a / 2; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main() {
    int m, n;
    int sum = 0;
    int min = 10000;

    cin >> m;
    cin >> n;

    for (int i = m; i <= n; i++) {
        if (i > 1 && is_prime(i)) {
            sum += i;
            if (i <= min)
                min = i;
        }
    }

    if (sum == 0)
        cout << -1 << endl;
    else
        cout << sum << endl << min << endl;

    return 0;
}