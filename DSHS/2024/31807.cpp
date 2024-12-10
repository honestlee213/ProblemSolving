#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, a, b, p = 0;
    cin >> l;
    vector<long long> ac_s(l + 1);

    cin >> ac_s[1];
    for (int i = 2; i < ac_s.size(); i++) {
        cin >> ac_s[i];
        if (ac_s[i] != ac_s[i - p] - ac_s[i - p - 1])
            p = 0;
        if (p == 0 && ac_s[i] == ac_s[1])
            p = i - 1;

        if (i > l / 2 && i % p == 0 && ac_s[i] == ac_s[i - p] - ac_s[i - p - 1]) {
            for (int j = i + 1; j < l + 1; j++)
                cin >> ac_s[j];
            ac_s.resize(p + 1);
        } else
            ac_s[i] += ac_s[i - 1];
    }

    cin >> a >> b;
    int rm_a = (a % p + p) % p, rm_b = (b % p + p) % p;
    if (rm_a > rm_b)
        cout << ((long long)((b - a) / p)) * ac_s[p] + (ac_s[p] - ac_s[rm_a]) + ac_s[rm_b];
    else
        cout << ((long long)((b - a) / p)) * ac_s[p] + (ac_s[rm_b] - ac_s[rm_a]);

    return 0;
}
