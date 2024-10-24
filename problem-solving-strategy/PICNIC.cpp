#include <iostream>
#include <vector>
using namespace std;

int res = 0;

int mate(vector<int> kid, vector<vector<int>> friendship) {
    int n = kid.size();
    int target;

    for (int i = 0; i < n; i++) {
        // if ()
    }
}

int main() {
    int c, n, m;

    cin >> c;

    vector<int> result(c, 0);

    for (int i = 0; i < c; i++) {
        cin >> n;
        cin >> m;

        vector<int> kid(n, 0);
        vector<vector<int>> friendship(n, vector<int>(n, 1));

        for (int j = 0; j < m; j++) {
            int kid_1, kid_2;

            cin >> kid_1;
            cin >> kid_2;

            friendship[kid_1][kid_2] = 1;
            friendship[kid_2][kid_1] = 1;
        }

        // mate()
    }

    return 0;
}
