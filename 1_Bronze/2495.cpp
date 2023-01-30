#include <iostream>
#include <string>
using namespace std;

int main() {
    for (int t = 0; t < 3; t++) {
        string str;
        cin >> str;
        int maxCnt = 1;
        int cnt = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1])
                cnt++;
            else {
                maxCnt = cnt > maxCnt ? cnt : maxCnt;
                cnt = 1;
            }
        }
        maxCnt = cnt > maxCnt ? cnt : maxCnt;
        cout << maxCnt << endl;
    }
}