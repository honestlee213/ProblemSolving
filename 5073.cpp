#include <iostream>
using namespace std;

int main() {
    while (1) {
        int a, b, c;
        int max = 0;

        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;

        if (a >= b && a >= c)
            max = a;
        else if (b >= a && b >= c)
            max = b;
        else
            max = c;

        if (max >= a + b + c - max)
            cout << "Invalid" << endl;
        else if (a == b && b == c)
            cout << "Equilateral" << endl;
        else if (a == b || b == c || c == a)
            cout << "Isosceles" << endl;
        else
            cout << "Scalene" << endl;
    }

    return 0;
}