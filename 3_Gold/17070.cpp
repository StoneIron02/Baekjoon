#include <iostream>

using namespace std;

int n;
bool matrix[17][17];
int dp[17][17][3];

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

    dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            // 가로
            if (j + 1 <= n && !matrix[i][j + 1])
                dp[i][j + 1][0] += dp[i][j][0];
            if (i + 1 <= n && j + 1 <= n && !matrix[i][j + 1] && !matrix[i + 1][j] && !matrix[i + 1][j + 1])
                dp[i + 1][j + 1][2] += dp[i][j][0];

            // 세로
            if (i + 1 <= n && !matrix[i + 1][j])
                dp[i + 1][j][1] += dp[i][j][1];
            if (i + 1 <= n && j + 1 <= n && !matrix[i][j + 1] && !matrix[i + 1][j] && !matrix[i + 1][j + 1])
                dp[i + 1][j + 1][2] += dp[i][j][1];

            // 대각선
            if (j + 1 <= n && !matrix[i][j + 1])
                dp[i][j + 1][0] += dp[i][j][2];
            if (i + 1 <= n && !matrix[i + 1][j])
                dp[i + 1][j][1] += dp[i][j][2];
            if (i + 1 <= n && j + 1 <= n && !matrix[i][j + 1] && !matrix[i + 1][j] && !matrix[i + 1][j + 1])
                dp[i + 1][j + 1][2] += dp[i][j][2];
        }
    }
    cout << (dp[n][n][0] + dp[n][n][1] + dp[n][n][2]);
}