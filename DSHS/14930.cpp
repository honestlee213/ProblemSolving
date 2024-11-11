#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    vector< pair<long long, long long> > bid(n);
    vector<long long> x(n);

    for (int i = 0; i < n; i++)
        cin >> bid[i].first >> bid[i].second;

    pair<long long, long long> red_pos = bid[0];

    sort(bid.begin(), bid.end());
    int red_idx = find(bid.begin(), bid.end(), red_pos) - bid.begin();

    for (int i = 0; i < n; i++)
        x[i] = bid[i].first + T * bid[i].second;

    sort(x.begin(), x.end());

    cout << x[red_idx];

    return 0;
}