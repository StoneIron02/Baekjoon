#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        char p;
        cin >> p;
        if (p == '#') break;
        cin.ignore();
        string str;
        getline(cin, str);
        int cnt = 0;
        for (char c : str) {
            if (c == p || c == p - 'a' + 'A') {
                cnt++;
            }
        }
        cout << p << " " << cnt << "\n";
    }
}