#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cost, chance_cost;
    int first_profit = 0, second_profit = 0;

    cin >> n;

    vector<int> profit(n);
    vector<int> net_profit(n);
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
        if (profit[i] >= first_profit) {
            second_profit = first_profit;
            first_profit = profit[i];
        } else if (profit[i] > second_profit)
            second_profit = profit[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost;

        if (profit[i] == first_profit)
            chance_cost = second_profit - cost;
        else
            chance_cost = first_profit - cost;

        net_profit[i] = profit[i] - chance_cost - cost;
    }

    cout << net_profit[0];
    for (int i = 1; i < n; i++)
        cout << " " << net_profit[i];

    return 0;
}
