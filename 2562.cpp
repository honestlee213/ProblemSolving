#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int n;
    int max = 1;

    for (int j = 1 ; j < 10; j++) {
        cin >> n;
        if (n >= max) {
            i = j;
            max = n;
        }
    }

    cout << max << endl << i << endl;

    return 0;
}