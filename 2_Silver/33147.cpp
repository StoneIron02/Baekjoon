#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];

  int g = gcd(N, K);

  vector<vector<int>> cycle_pos(g), cycle_set(g);
  for (int i = 0; i < N; ++i) {
    cycle_pos[i % g].push_back(i);
    cycle_set[i % g].push_back(A[i]);
  }

  for (int r = 0; r < g; r++) {
    vector<int> need;
    for (int idx : cycle_pos[r]) need.push_back(idx);
    ranges::sort(need);
    ranges::sort(cycle_set[r]);
    vector<int> target;
    for (int idx : need) target.push_back(idx);
    if (cycle_set[r] != target) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
