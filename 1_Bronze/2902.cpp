#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    string result;
    result += str[0];
    bool add = false;
    for (char c : str) {
        if (add) {
            result += c;
            add = false;
        }
        if (c == '-') {
            add = true;
        }
    }
    cout << result;
}