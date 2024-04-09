#include <iostream>
using namespace std;

int n, m;
int mem[101];
int cost[101];
long long dp[101][10001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> mem[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 10000; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - cost[i] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + mem[i]);
      }
    }
  }

  for (int j = 0; j <= 10000; j++) {
    if (dp[n][j] >= m) {
      cout << j;
      break;
    }
  }
}