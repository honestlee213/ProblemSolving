#include <iostream>
using namespace std;

int main() {
    int n;
    int min = 1667;

    cin >> n;

    for (int i = 0; i <= n / 5; i++)
        if ((n - 5 * i) % 3 == 0 && i + (n - 5 * i) / 3 < min)
            min = i + (n - 5 * i) / 3;
    
    if (min != 1667)
        cout << min << endl;
    else
        cout << -1 << endl;

    return 0;
}