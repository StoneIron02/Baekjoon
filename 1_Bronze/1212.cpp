#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string octal_s;
    cin >> octal_s;
    string bit_s = "";
    for (char c : octal_s) {
        int oct = c - '0';
        string bit = "";
        for (int i = 0; i < 3; i++) {
            int b = oct % 2;
            bit = to_string(b) + bit;
            oct /= 2;
        }
        bit_s += bit;
    }
    while (bit_s[0] == '0')
        bit_s = bit_s.substr(1);
    if (bit_s == "")
        cout << 0;
    else
        cout << bit_s;
}