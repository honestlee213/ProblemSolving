#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b;
    cin >> c;

    b += c;
    
    if (b >= 60) {
        int d = b / 60;
        b = b % 60;

        a += d;

        if (a >= 24) {
            a = a % 24;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}