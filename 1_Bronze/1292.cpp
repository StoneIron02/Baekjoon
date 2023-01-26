#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int curNum = 1;
    int curCnt = 0;
    for (int i = 1; i < a; i++) {
        curCnt++;
        if (curCnt == curNum) {
            curNum++;
            curCnt = 0;
        }
    }
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += curNum;
        curCnt++;
        if (curCnt == curNum) {
            curNum++;
            curCnt = 0;
        }
    }
    cout << sum;
}