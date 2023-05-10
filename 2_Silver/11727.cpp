#include <iostream>

using namespace std;

int dp[1001];

void dynammic_programming(int n) {
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    dynammic_programming(n);
    cout << dp[n];
}