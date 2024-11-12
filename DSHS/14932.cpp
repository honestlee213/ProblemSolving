#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> next_btn(int row, int col, int dis, char dir) {
    switch (dir) {
        case 'U':
            return make_pair(row - dis, col);
            break;
        case 'D':
            return make_pair(row + dis, col);
            break;
        case 'L':
            return make_pair(row, col - dis);
            break;
        case 'R':
            return make_pair(row, col + dis);
            break;
        default:
            break;
    }
    return make_pair(row, col);
}

void open_the_door(vector< vector< pair<int, char> > > safe) {
    int n = safe.size();
    int row = 0;
    int col = 0;
    vector< vector<int> > track(n, vector<int>(n));

    track[0][0] = 1;

    for (int iter = 1; iter < n * n; iter++) {
        pair<int, int> nxt_btn = next_btn(row, col, safe[row][col].first, safe[row][col].second);
        if (track[nxt_btn.first][nxt_btn.second] == 1) {
            cout << "TOO SAFE";
            return;
        } else {
            row = nxt_btn.first;
            col = nxt_btn.second;
            track[nxt_btn.first][nxt_btn.second] = 1;
        }
    }

    cout << "THIEF LOVE IT!";
}

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector< vector< pair<int, char> > > safe(n, vector< pair<int, char> >(n, make_pair(0, 'A')));
    vector< vector<int> > track(n, vector<int>(n));
    vector< pair<int, int> > zeros;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string btn;
            cin >> btn;

            safe[i][j] = make_pair(stoi(btn.substr(0, btn.size() - 1)), btn[btn.size() - 1]);

            pair<int, int> nxt_btn = next_btn(i, j, safe[i][j].first, safe[i][j].second);
            track[nxt_btn.first][nxt_btn.second]++;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (track[i][j] == 0)
                zeros.push_back(make_pair(i, j));
    
    if (zeros.size() == 1) {
        cout << zeros[0].first + 1 << " " << zeros[0].second + 1;
        return 0;
    } else if (zeros.size() > 1) {
        cout << "TOO SAFE";
        return 0;
    }

    open_the_door(safe);

    return 0;
}