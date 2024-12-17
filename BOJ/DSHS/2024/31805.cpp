#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int diff(string a, string b) {
    for (int i = 0; i < a.length(); i++)
        if (a[i] == b[i])
            return false;
    if (a.length() != b.length())
        return false;

    return true;
}

bool comp(queue<int> &a, queue<int> &b) {
    return a.size() > b.size();
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string prob;
    cin >> n;
    cin >> prob;
    string change = prob;

    vector< queue<int> > ch_pos(26);
    char maj_ch, min_ch;
    int maj = 0, min = 0;

    if (n == 1) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < n; i++)
        ch_pos[prob[i] - 'a'].push(i + 1);
    for (int i = 0; i < 26; i++) {
        if (ch_pos[i].size() > n / 2) {
            cout << -1;
            return 0;
        }
    }

    sort(ch_pos.begin(), ch_pos.end(), comp);

    int i = 0, j = 1;
    while (i < 26) {
        if (ch_pos[i].size() == 0) {
            i = j;
            j++;
            continue;
        }
        if (j >= 26) {
            if (ch_pos[i].size() == 0)
                break;
            else {
                
            }
        } else if (ch_pos[j].size() == 0) {
            j++;
            continue;
        }
    }

    return 0;
}
