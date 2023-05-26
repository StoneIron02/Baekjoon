#include <iostream>

using namespace std;

int dp[10001];
int value[101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
        if (value[i] > k) {
            n--;
            i--;
        }
    }

    if (n == 0) {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - value[i] >= 0) {
                dp[j] += dp[j - value[i]];
            }
        }
    }

    cout << dp[k];
}