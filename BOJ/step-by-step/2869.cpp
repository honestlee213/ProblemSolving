#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, v;

    cin >> a >> b >> v;

    cout << 1 + (int)ceil((double) (v - a) / (a - b)) << endl;

    return 0;
}