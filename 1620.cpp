#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> book;
    map<string, int> book_inv;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        
        book.push_back(name);
        book_inv[name] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        
        if ('0' <= name[0] && name[0] <= '9')
            cout << book[stoi(name) - 1] << "\n";
        else
            cout << book_inv[name] << "\n";
    }

    return 0;
}