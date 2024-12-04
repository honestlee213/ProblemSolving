#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool ruled(string n) {
    bool mode = true;   // 'true' for raise, 'false' for lower

    if (n[0] >= n[1])
        return false;
    for (int i = 1; i < n.length() - 2; i++) {
        if ((mode && n[i] < n[i + 1]) || (!mode && n[i] > n[i + 1]))
            continue;
        else if (n[i] == n[i + 1])
            return false;
        else if (mode)
            mode = false;
        else
            return false;
    }
    if (n[n.length() - 2] <= n[n.length() - 1])
        return false;

    return true;
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, a, b;
    cin >> t;
    vector<int> accu_sum(1000000);
    vector<int> ans(t);

    for (int n = 120 - 1; n < 1000000; n++)
        if (ruled(to_string(n + 1)))
            accu_sum[n] = accu_sum[n - 1] + 1;
        else
            accu_sum[n] = accu_sum[n - 1];

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        if (a < 120)
            ans[i] = accu_sum[b - 1];
        else
            ans[i] = accu_sum[b - 1] - accu_sum[a - 2];
    }

    cout << ans[0];
    for (int i = 1; i < t; i++)
        cout << '\n' << ans[i];

    return 0;
}
