#include <iostream>
using namespace std;

long long combinate(long long n) {
    if (n == 2)
        return 1;
    else
        return (n - 1) * combinate(n - 2);
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    if (n % 2 == 0)
        cout << combinate(n);
    else
        cout << n * combinate(n - 1);

    return 0;
}
