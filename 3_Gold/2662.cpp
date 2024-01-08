#include <iostream>
using namespace std;

int n, m;
int arr[301][21];
int dp[301][21];
int value[301][21];

void track(int i, int j) {
  if (j == 0) return;
  track(i - value[i][j], j - 1);
  cout << value[i][j] << " ";
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    for (int j = 1; j <= m; j++) {
      cin >> arr[num][j];
    }
  }

  for (int j = 1; j <= m; j++) {
    for (int i = 0; i <= n; i++) {
      for (int k = 0; k <= n; k++) {
        if (i + k > n) continue;
        if (dp[i + k][j] < dp[k][j - 1] + arr[i][j]) {
          dp[i + k][j] = dp[k][j - 1] + arr[i][j];
          value[i + k][j] = i;
        }
      }
    }
  }

  cout << dp[n][m] << "\n";
  track(n, m);
}