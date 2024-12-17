#include <iostream>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;
    
    int b1 = b % 10;
    int b2 = (b / 10) % 10;
    int b3 = (b / 100) % 10;

    cout << a * b1 << endl << a * b2 << endl << a * b3 << endl << a * b << endl;

    return 0;
}