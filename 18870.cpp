#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    // 마법의 주문
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> table;
    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        arr.push_back(num);
        if (table.find(num) == table.end())
            table[num] = 1;
    }
    
    int order = 0;
    for (auto it : table) {
        table[it.first] = order;
        order++;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        cout << table[arr[i]];
        if (i < arr.size() - 1)
            cout << " ";
    }

    return 0;
}