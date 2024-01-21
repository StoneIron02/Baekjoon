#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& str1, const string& str2) {
    if (str1.size() < str2.size()) {
        return true;
    } else if (str1.size() > str2.size()) {
        return false;
    } else {
        int i = 0;
        while (i < str1.size() && str1[i] == str2[i]) {
            i++;
        }
        if (i == str1.size()) {
            return true;
        }
        return (str1[i] < str2[i]);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> vec;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        string curNumStr;
        for (char c : str) {
            if (c >= '0' && c <= '9') {
                curNumStr += c;
            } else {
                if (!curNumStr.empty()) {
                    while (curNumStr[0] == '0' && curNumStr.size() > 1) {
                        curNumStr = curNumStr.substr(1);
                    }
                    vec.push_back(curNumStr);
                    curNumStr = "";
                }
            }
        }
        if (!curNumStr.empty()) {
            while (curNumStr[0] == '0' && curNumStr.size() > 1) {
                curNumStr = curNumStr.substr(1);
            }
            vec.push_back(curNumStr);
            curNumStr = "";
        }
    }
    sort(vec.begin(), vec.end(), compare);
    for (const auto& i : vec) {
        cout << i << "\n";
    }
}