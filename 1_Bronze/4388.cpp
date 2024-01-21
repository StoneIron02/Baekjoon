#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1 == "0" && str2 == "0") break;

        if (str1.size() < str2.size()) {
            string tmp = str1;
            str1 = str2;
            str2 = tmp;
        }

        while (str1.size() != str2.size()) {
            str2 = "0" + str2;
        }

        int carryCnt = 0;
        int carry = 0;
        for (int i = str1.size() - 1; i >= 0; i--) {
            int d1 = str1[i] - '0';
            int d2 = str2[i] - '0';
            int r = d1 + d2 + carry;
            if (r >= 10) {
                carryCnt++;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        cout << carryCnt << "\n";
    }
}