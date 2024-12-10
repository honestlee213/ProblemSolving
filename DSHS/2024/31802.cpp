#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, a, b;
    cin >> p;
    vector<long long> accu_sum(p + 1);

    for (int i = 1; i <= p; i++) {
        cin >> accu_sum[i];
        accu_sum[i] += accu_sum[i - 1];
    }

    cin >> a >> b;
    int rem_a = (a % p + p) % p, rem_b = (b % p + p) % p;
    if (rem_a > rem_b)
        cout << ((long long)((b - a) / p)) * accu_sum[p] + (accu_sum[p] - accu_sum[rem_a]) + accu_sum[rem_b];
    else
        cout << ((long long)((b - a) / p)) * accu_sum[p] + (accu_sum[rem_b] - accu_sum[rem_a]);

    return 0;
}
