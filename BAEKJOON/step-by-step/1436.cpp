#include <iostream>
#include <string>
using namespace std;


int main() {
    int n;
    int i = 0;

    cin >> n;

    for (int m = 666; i < n; m++) {
        if (to_string(m).find("666") != string::npos) {
            i++;
            if (i == n)
                cout << m << endl;
        }
    }

    return 0;
}