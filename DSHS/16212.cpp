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

    vector<int> a(n);

    for (int i = 0; i < a.size(); i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
        cout << " " << a[i];

    return 0;
}
