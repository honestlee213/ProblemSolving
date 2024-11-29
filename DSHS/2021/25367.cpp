#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    long long x, y;

    cin >> q;
    vector<long long> ans(q);

    for (int i = 0; i < q; i++) {
        cin >> x >> y;

        for (long long k = 0; k <= x / 2; k++) {
            if ((k ^ (x - k)) == y)
                ans[i] += 2;
            if (k == x - k)
                ans[i] -= 1;
        }
    }

    cout << ans[0];
    for (int i = 1; i < q; i++)
        cout << "\n" << ans[i];

    return 0;
}
