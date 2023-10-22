#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int r, c, n;
    cin >> r >> c >> n;
    int rCnt, cCnt;

    if (r % n == 0)
        rCnt = r / n;
    else
        rCnt = r / n + 1;

    if (c % n == 0)
        cCnt = c / n;
    else
        cCnt = c / n + 1;

    cout << (1LL * rCnt * cCnt);
}