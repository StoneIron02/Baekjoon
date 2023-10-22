#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string C;
        getline(cin, C);
        map<char, char> rule;
        for (int i = 0; i < 26; i++) {
            char c;
            cin >> c;
            rule['A' + i] = c;
        }
        for (char c : C) {
            if (c == ' ')
                cout << ' ';
            else {
                cout << rule[c];
            }
        }
        cout << "\n";
        cin.ignore();
    }
}