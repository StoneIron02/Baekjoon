#include <iostream>

using namespace std;

void cal(string n_str, string pow_str) {
    for (int i = 0; i < n_str.size(); i++) {
        if (pow_str[pow_str.size() - i - 1] != n_str[n_str.size() - i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string n_str = to_string(n);
        int pow = n * n;
        string pow_str = to_string(pow);
        cal(n_str, pow_str);
    }
}