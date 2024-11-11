#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n, m;
    vector<int> cards;

    cin >> n >> m;

    int min_gap = m;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        cards.push_back(card);
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum <= m && m - sum < min_gap)
                    min_gap = m - sum;
            }
        }
    }

    cout << m - min_gap;

    return 0;
}