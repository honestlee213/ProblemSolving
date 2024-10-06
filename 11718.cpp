#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    while (1) {
        getline(cin, s);
        if (s.length() == 0)
            break;
        cout << s << endl;
    }

    return 0;
}