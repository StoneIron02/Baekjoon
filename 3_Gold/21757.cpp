#include <iostream>

using namespace std;

int n;
long long arr[100'001];
long long dp[100'001][4];

void zero() {
    long long cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (arr[i] == 0)
            cnt++;
    }
    cout << (cnt * (cnt - 1) * (cnt - 2) / 6);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    if (arr[n] % 4 != 0) {
        cout << 0;
        exit(0);
    }
    long long div = arr[n] / 4;
    if (div == 0) {
        zero();
        exit(0);
    }
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        dp[i][3] = dp[i - 1][3];
        if (arr[i] % div == 0 && abs(arr[i] / div) < 4) {
            int num = abs(arr[i] / div);
            if (num == 1)
                dp[i][num] += 1;
            else
                dp[i][num] += dp[i][num - 1];
        }
    }

    cout << dp[n][3];
}