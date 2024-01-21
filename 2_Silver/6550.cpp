#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s, t;
    while (cin >> s >> t) {
        int i = 0;
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == s[i]) {
                i++;
            }
        }
        if (i == s.size()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}