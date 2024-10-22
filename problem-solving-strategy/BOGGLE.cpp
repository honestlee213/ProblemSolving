#include <iostream>
#include <string>
#include <vector>
using namespace std;

char boggle[5][5];

bool hasWord(int y, int x, const string& word) {
    if (y < 0 || y >= 5 || x < 0 || x >= 5 || boggle[y][x] != word[0])
        return false;
    if (word.length() == 1)
        return true;
    
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int dir = 0; dir < 8; dir++)
        if (hasWord(y + dy[dir], x + dx[dir], word.substr(1)))
            return true;
    
    return false; 
}

int main() {
    int c, n;
    string word;

    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> boggle[0];
        cin >> boggle[1];
        cin >> boggle[2];
        cin >> boggle[3];
        cin >> boggle[4];
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> word;
            bool isExist = false;
            for (int a = 0; a < 5; a++)
                for (int b = 0; b < 5; b++)
                    if (hasWord(a, b, word))
                        isExist = true;
            if (isExist)
                cout << word << " YES" << endl;
            else
                cout << word << " NO" << endl;
        }
    }

    return 0;
}