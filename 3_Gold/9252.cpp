#include <iostream>

using namespace std;

string a, b;
int dp[1001][1001];
int p[1001][1001];

void LCS_arr(int i, int j) {
    if (i == 0 || j == 0) return;
    switch (p[i][j]) {
        case 1:
            LCS_arr(i - 1, j - 1);
            cout << b[j - 1];
            break;
        case 2:
            LCS_arr(i - 1, j);
            break;
        case 3:
            LCS_arr(i, j - 1);
            break;
    }
}

void LCS() {
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                p[i][j] = 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    p[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j - 1];
                    p[i][j] = 3;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    LCS();
    cout << dp[a.size()][b.size()] << "\n";
    LCS_arr(a.size(), b.size());
}