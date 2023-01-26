#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    string p;
    getline(cin, str);
    cin >> p;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            cout << ' ';
            continue;
        }

        char c = p[i % p.size()];
        int i_c = c - 'a' + 1;
        char converted_char = str[i] - i_c;
        if (converted_char < 'a')
            converted_char += 26;
        cout << converted_char;
    }
}