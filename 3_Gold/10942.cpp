#include <iostream>

using namespace std;

int arr[2001];
bool dp[2001][2001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++) // 홀
        dp[i][i] = true;
    for (int i = 1; i <= n - 1; i++)
        dp[i][i + 1] = arr[i] == arr[i + 1];

    for (int l = 3; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = arr[i] == arr[j] && dp[i + 1][j - 1];
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}