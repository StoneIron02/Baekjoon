#include <iostream>
using namespace std;

int arr[301][301];
int sum[301][301];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    int result = sum[x][y] - sum[x][v - 1] - sum[u - 1][y] + sum[u - 1][v - 1];
    cout << result << "\n";
  }
}