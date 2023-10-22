#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int cnt = 0;
    while (n >= 2 && m >= 1 && m + n >= k + 3) {
        cnt++;
        n -= 2;
        m -= 1;
    }
    cout << cnt;
}