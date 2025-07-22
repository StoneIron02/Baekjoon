#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m, a;
  cin >> n >> m >> a;

  int total = n * m;
  vector<int> arr(total);

  for (int i = 0; i < total; ++i) {
    cin >> arr[i];
  }

  int res = 0;

  for (int floor = 0; floor < n - 1; ++floor) {
    for (int apt = 0; apt < m; ++apt) {
      int lower_idx = floor * m + apt;
      int upper_idx = lower_idx + m;

      if (arr[upper_idx] > 2 * arr[lower_idx]) {
        res += a;
      }
    }
  }

  cout << res;
}