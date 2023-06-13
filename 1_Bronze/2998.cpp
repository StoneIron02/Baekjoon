#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string octal;
    cin >> octal;
    string result = "";
    while (octal.size() % 3 != 0)
        octal = "0" + octal;

    for (int i = 0; i < octal.size(); i += 3) {
        string cur = octal.substr(i, 3);

        if (cur == "000")
            result += "0";
        if (cur == "001")
            result += "1";
        if (cur == "010")
            result += "2";
        if (cur == "011")
            result += "3";
        if (cur == "100")
            result += "4";
        if (cur == "101")
            result += "5";
        if (cur == "110")
            result += "6";
        if (cur == "111")
            result += "7";
    }
    cout << result;
}