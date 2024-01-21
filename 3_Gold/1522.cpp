#include <iostream>

using namespace std;

int getCnt(string str) {
    int i = 0, j = str.size() - 1;
    int cnt = 0;
    while (i < j) {
        if (str[i] == 'a') {
            i++;
            continue;
        }
        if (str[j] == 'b') {
            j--;
            continue;
        }
        cnt++;
        str[i] = 'a';
        str[j] = 'b';
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    int minCnt = INT32_MAX;
    for (int i = 0; i < str.size(); i++) {
        char top = str[0];
        str += top;
        str = str.substr(1, str.size());
        minCnt = min(minCnt, getCnt(str));
    }
    cout << minCnt;
}