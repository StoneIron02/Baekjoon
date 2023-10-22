#include <iostream>

using namespace std;

int dp[1'000'001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= 1'000'000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1'000'000'000;

    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << "\n";
    }
    else if (n < 0 && n % 2 == 0) {
        cout << -1 << "\n";
    } else {
        cout << 1 << "\n";
    }

    if (n < 0)
        n = -n;
    cout << dp[n];
}