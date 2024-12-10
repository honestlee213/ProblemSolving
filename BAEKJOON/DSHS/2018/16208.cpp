#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    unsigned long long total = 0;
    unsigned long long partial_sum = 0;

    cin >> n;
    unsigned long long num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        total += partial_sum * num;
        partial_sum += num;
    }
    
    cout << total;

    return 0;
}
