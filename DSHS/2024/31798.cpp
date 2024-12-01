#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 || b == 0)
        cout << (int)(pow(c, 2) - a - b);
    else
        cout << (int)sqrt(a + b);

    return 0;
}
