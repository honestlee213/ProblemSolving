#include <iostream>
using namespace std;

int main() {
    int row, col;
    int max = 0;
    int num[9][9];

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> num[i - 1][j - 1];
            if (num[i - 1][j - 1] >= max) {
                max = num[i - 1][j - 1];
                row = i;
                col = j;
            }
        }
    }

    cout << max << endl << row << " " << col << endl;

    return 0;
}