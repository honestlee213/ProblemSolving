#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> count(1);
    int max = 1;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (num > max) {
            count.insert(count.end(), num - max, 0);
            count[num - 1]++;
            max = num;
        } else {
            count[num - 1]++;
        }
    }

    for (int i = 0; i < count.size(); i++)
        if (count[i] != 0)
            for (int j = 0; j < count[i]; j++)
                cout << i + 1 << '\n';

    return 0;
}