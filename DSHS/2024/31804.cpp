#include <iostream>
#include <vector>
using namespace std;

int minimum(int old, int new1, int new2) {  // Guaranteed new1 > 0, new2 > 0
    if (old > 0 && old < new1 && old < new2)
        return old;
    else if (new1 < new2)
        return new1;
    return new2;
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    vector<int> min(b + 1);
    vector<int> min_chanced(b + 1);

    for (int i = a; i < b; i++) {   // min[a]=0부터 시작해서 min[a + 1]~min[b]까지 채움
        if (i + 1 <= b) {
            min[i + 1] = minimum(min[i + 1], min[i] + 1, min[i] + 1);
            min_chanced[i + 1] = minimum(min_chanced[i + 1], min[i] + 1, min_chanced[i] + 1);
        }
        if (2 * i <= b) {
            min[2 * i] = minimum(min[2 * i], min[i] + 1, min[i] + 1);
            min_chanced[2 * i] = minimum(min_chanced[2 * i], min[i] + 1, min_chanced[i] + 1);
        }
        if (10 * i <= b)
            min_chanced[10 * i] = minimum(min_chanced[10 * i], min[i] + 1, min[i] + 1);
    }

    cout << minimum(min_chanced[b], min[b], min[b]);

    return 0;
}
