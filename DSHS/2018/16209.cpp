#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;
    vector<int> pos;
    vector<int> neg;
    int zeros = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0)
            zeros++;
        else if (num < 0)
            neg.push_back(num);
        else
            pos.push_back(num);
    }

    sort(neg.rbegin(), neg.rend());
    sort(pos.begin(), pos.end());

    if (neg.size() == 1)
        cout << neg[0];
    else if (neg.size() > 1)
        cout << neg[1];
    if (neg.size() % 2 == 0) {
        for (int i = 3; i < neg.size(); i += 2)
            cout << " " << neg[i];
        for (int i = neg.size() - 2; i >= 0; i -= 2)
            cout << " " << neg[i];
    } else if (neg.size() > 1) {
        for (int i = 3; i < neg.size(); i += 2)
            cout << " " << neg[i];
        for (int i = neg.size() - 1; i >= 0; i -= 2)
            cout << " " << neg[i];
    }

    if (neg.size() > 0)
        for (int i = 0; i < zeros; i++)
            cout << " 0";
    else {
        if (zeros > 0)
            cout << "0";
        for (int i = 1; i < zeros; i++)
            cout << " 0";
    }

    if (pos.size() > 0) {
        if (zeros + neg.size() > 0)
            cout << " " << pos[0];
        else
            cout << pos[0];
    }
    if (pos.size() % 2 == 0) {
        for (int i = 2; i < pos.size(); i += 2)
            cout << " " << pos[i];
        for (int i = pos.size() - 1; i > 0; i -= 2)
            cout << " " << pos[i];
    } else {
        for (int i = 2; i < pos.size(); i += 2)
            cout << " " << pos[i];
        for (int i = pos.size() - 2; i > 0; i -= 2)
            cout << " " << pos[i];
    }

    return 0;
}
