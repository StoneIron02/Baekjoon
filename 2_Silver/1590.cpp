#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    int minTime = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int s, l, c;
        cin >> s >> l >> c;
        for (int j = 0; j < c; j++) {
            long long curTime = 1LL * s + l * j;
            if (curTime > INT32_MAX) break;
            if (curTime < t) continue;
            if (minTime > curTime) {
                minTime = curTime;
            }
        }
    }
    if (minTime == INT32_MAX) {
        cout << -1;
        return 0;
    }
    cout << (minTime - t);
}