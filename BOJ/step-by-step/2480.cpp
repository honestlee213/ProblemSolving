#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    int max = 0;

    cin >> a >> b >> c;

    if (a == b && b == c)
        cout << 10000 + a * 1000 << endl;
    else if (a == b || a == c)
        cout << 1000 + a * 100 << endl;
    else if (b == c)
        cout << 1000 + b * 100 << endl;
    else {
        if (a > max)
            max = a;
        if (b > max)
            max = b;
        if (c > max)
            max = c;
        cout << max * 100 << endl;
    }

    return 0;
}