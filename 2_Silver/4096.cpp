#include <iostream>

using namespace std;

bool isPal(string str) {
    int i = 0, j = str.size() - 1;
    while (i < j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        string str;
        cin >> str;
        if (str == "0") break;

        int cnt = 0;
        int strSize = str.size();
        while (!isPal(str)) {
            cnt++;
            int num = stoi(str);
            num++;
            string newStr = to_string(num);
            while (newStr.size() < strSize) {
                newStr = '0' + newStr;
            }
            str = newStr;
        }
        cout << cnt << "\n";
    }
}