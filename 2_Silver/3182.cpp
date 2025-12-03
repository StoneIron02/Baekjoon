#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> next(N + 1);
  for (int i = 1; i <= N; ++i) cin >> next[i];

  int best_value = 0;
  int best_idx = 1;

  for (int s = 1; s <= N; ++s) {
    vector<bool> visited(N + 1, false);
    int cnt = 0;
    int cur = s;

    while (!visited[cur]) {
      visited[cur] = true;
      ++cnt;
      cur = next[cur];
    }

    if (cnt > best_value || (cnt == best_value && s < best_idx)) {
      best_value = cnt;
      best_idx = s;
    }
  }

  cout << best_idx << "\n";
}