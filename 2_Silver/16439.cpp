#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> a(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;

  for (int i = 0; i < M; i++) {
    int sum = 0;
    for (int p = 0; p < N; p++) {
      sum += a[p][i];
    }
    ans = max(ans, sum);
  }

  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      int sum = 0;
      for (int p = 0; p < N; p++) {
        sum += max(a[p][i], a[p][j]);
      }
      ans = max(ans, sum);
    }
  }

  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      for (int k = j + 1; k < M; k++) {
        int sum = 0;
        for (int p = 0; p < N; p++) {
          sum += max({a[p][i], a[p][j], a[p][k]});
        }
        ans = max(ans, sum);
      }
    }
  }

  cout << ans;
}
