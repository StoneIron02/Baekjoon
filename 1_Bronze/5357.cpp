#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        char before = str[0];
        cout << before;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == before) continue;
            before = str[i];
            cout << before;
        }
        cout << "\n";
    }
}