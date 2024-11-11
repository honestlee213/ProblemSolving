#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l;
    cin >> l;

    vector<int> score(l);
    long long max_score = 0;
    int max_d = 1;

    for (int i = 0; i < l; i++) {
        cin >> score[i];
        max_score += score[i];
    }

    for (int d = 2; d <= l; d++) {
        long long sum_score = 0;

        for (int j = d - 1; j < l; j += d)
            sum_score += score[j];
        
        if (sum_score > max_score) {
            max_d = d;
            max_score = sum_score;
        }
    }

    if (max_score > 0)
        cout << max_d << " " << max_score;
    else
        cout << "0 0";

    return 0;
}