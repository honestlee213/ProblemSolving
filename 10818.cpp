#include <iostream>
using namespace std;

int main(){
    int n, a;
    int min = 1000000;
    int max = -1000000;

    cin >> n;

    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a <= min) {
            min = a;
        }
        if (a >= max) {
            max = a;
        }
    }

    cout << min << " " << max << endl;

    return 0;
}