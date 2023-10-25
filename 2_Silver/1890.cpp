#include <iostream>

using namespace std;

int n;
int matrix[101][101];
long long dp[101][101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int d = matrix[i][j];
            if (d == 0) continue;
            if (i + d <= n) {
                dp[i + d][j] += dp[i][j];
            }
            if (j + d <= n) {
                dp[i][j + d] += dp[i][j];
            }
        }
    }

    cout << dp[n][n];
}