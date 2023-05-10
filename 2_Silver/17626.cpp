#include <iostream>

using namespace std;

int dp[50001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= 50000; i++) {
        int m = INT32_MAX;
        for (int j = 1; j * j <= i; j++) {
            if (m > dp[i - j * j])
                m = dp[i - j * j];
        }
        dp[i] = m + 1;
    }
    cout << dp[n];
}