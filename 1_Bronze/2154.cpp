#include <iostream>

using namespace std;

int n;
string n_str;

bool found(string& str, int& p) {
    if (str.size() - p + 1 < n_str.size())
        return false;

    for (int i = 0; i < n_str.size(); i++) {
        if (str[p + i] != n_str[i])
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    n_str = to_string(n);
    string str;
    for (int i = 1; i <= n; i++)
        str += to_string(i);

    for (int i = 0; i < str.size(); i++) {
        if (found(str, i)) {
            cout << (i + 1);
            break;
        }
    }
}