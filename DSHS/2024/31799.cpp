#include <iostream>
#include <string>
using namespace std;

int main() {
    // Magic spell
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string grades;
    string last = "C-";
    string now = "";

    cin >> n;
    cin >> grades;

    for (int i = 0; i < grades.length(); i++) {
        now += grades[i];

        if (i == grades.length() - 1 || grades[i + 1] >= 'A') {
            if (now == "C-" || now == "C0" || now == "C" || now == "C+")
                cout << 'B';
            else if (now == "B-" || now == "B0" || now == "B") {
                if (last == "C-" || last == "C0" || last == "C" || last == "C+")
                    cout << 'D';
                else
                    cout << 'B';
            } else if (now == "A-" || now == "B+") {
                if (last == "A+" || last == "A0" || last == "A" || last == "A-" || last == "B+")
                    cout << 'D';
                else
                    cout << 'P';
            } else if (now == "A0" || now == "A") {
                if (last == "A+" || last == "A0" || last == "A")
                    cout << 'P';
                else
                    cout << 'E';
            } else
                cout << 'E';
            
            last = now;
            now = "";
        }
    }

    return 0;
}
