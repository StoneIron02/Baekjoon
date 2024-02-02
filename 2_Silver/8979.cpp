#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<tuple<int, int, int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    int num, a, b, c;
    cin >> num >> a >> b >> c;
    arr[i] = {a, b, c, num};
  }

  sort(arr.begin(), arr.end(), greater<>());

  int rank;
  for (rank = 0; rank < n; rank++) {
    if (get<3>(arr[rank]) == k) break;
  }

  auto [va, vb, vc, vv] = arr[rank];
  while (rank > 0) {
    auto& [a, b, c, v] = arr[rank - 1];
    if (a == va && b == vb && c == vc) {
      rank--;
    } else {
      break;
    }
  }
  cout << (rank + 1);
}