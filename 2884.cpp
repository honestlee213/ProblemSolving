#include <iostream>
using namespace std;

int main() {
    int h, m;

    cin >> h >> m;
    
    if (m >= 45) {
        m -= 45;
    } else if (h >= 1) {
        h -= 1;
        m += 15;
    } else {
        h = 23;
        m += 15;
    }

    cout << h << " " << m << endl;

    return 0;
}