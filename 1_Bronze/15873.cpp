#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    int a, b = 0;
    if (str[0] == '1' && str[1] == '0') {
        a = 10;
        for (char c : str.substr(2)) {
            b *= 10;
            b += c - '0';
        }
    }
    else {
        a = str[0] - '0';
        for (char c : str.substr(1)) {
            b *= 10;
            b += c - '0';
        }
    }
    cout << (a + b);
}