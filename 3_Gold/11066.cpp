#include <iostream>
using namespace std;

int arr[501];
int scale[501][501];
int dp[501][501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> scale[i][i];
        }

        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = INT32_MAX;
                for (int k = i; k <= j - 1; k++) {
                    int scaleSum = scale[i][k] + scale[k + 1][j];
                    int q = dp[i][k] + dp[k + 1][j] + scaleSum;
                    if (dp[i][j] > q) {
                        dp[i][j] = q;
                        scale[i][j] = scaleSum;
                    }
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
}