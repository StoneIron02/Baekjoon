#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int size[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> size[i] >> size[i + 1];
    }

    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT32_MAX;
            // find the position that has minimum number of operations.
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + size[i - 1] * size[k] * size[j];
                if (dp[i][j] > q) {
                    dp[i][j] = q;
                }
            }
        }
    }

    cout << dp[1][n];
}