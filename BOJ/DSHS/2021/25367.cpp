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
    vector<long long> ans(q, 1);

    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        bool up = false;

        while (x > 0) {
            int sm = (int)(x & 1);
            int xr = (int)(y & 1);

            if ((!up && sm != xr) || (up && sm == xr)) {
                ans[i] = 0;
                break;
            }

            if (xr == 1)
                ans[i] *= 2;

            x >>= 1;
            y >>= 1;
            int sm_nxt = (int)(x & 1);
            int xr_nxt = (int)(y & 1);

            if (xr == 0)
                if ((!up && sm_nxt != xr_nxt) || (up && sm_nxt == xr_nxt))
                    up = !up;
        }

        if (x == 0 && y != 0)
            ans[i] = 0;
    }

    cout << ans[0];
    for (int i = 1; i < q; i++)
        cout << "\n" << ans[i];

    return 0;
}
