#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string binary1, binary2;
    cin >> binary1 >> binary2;

    if (binary1.size() < binary2.size()) {
        string temp = binary1;
        binary1 = binary2;
        binary2 = temp;
    }

    string result = "";
    bool over = 0;
    int i;
    for (i = 0; i < binary2.size(); i++) {
        bool a = binary1[binary1.size() - 1 - i] - '0';
        bool b = binary2[binary2.size() - 1 - i] - '0';
        bool sum = a ^ b ^ over;
        over = a & b | a & over | b & over;
        result = to_string(sum) + result;
    }
    for (; i < binary1.size(); i++) {
        bool a = binary1[binary1.size() - 1 - i] - '0';
        bool sum = a ^ over;
        over = a & over;
        result = to_string(sum) + result;
    }
    if (over)
        result = "1" + result;
    while (result[0] == '0' && result.size() > 1)
        result = result.substr(1);
    cout << result;
}