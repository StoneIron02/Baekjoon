#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool arr[26] {false};
        for (char c : s) {
            arr[c - 'A'] = true;
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (!arr[i]) {
                sum += 'A' + i;
            }
        }
        cout << sum << "\n";
    }
}