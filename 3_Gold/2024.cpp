#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int M;
  while (cin >> M) {
    vector<pair<int, int>> arr;
    while (true) {
      int l, r;
      cin >> l >> r;
      if (l == 0 && r == 0) break;

      if (l <= 0 && r <= 0) continue;
      if (l <= 0 && r > 0) l = 0;
      arr.emplace_back(l, r);
    }
    sort(arr.begin(), arr.end());

    bool flag = true;
    int cnt = 0;
    int idx = 0;
    int latestRight = 0;
    while (idx < arr.size()) {
      if (latestRight >= M) break;

      int nextRight = -1;
      while (idx < arr.size() && arr[idx].first <= latestRight) {
        if (arr[idx].second > nextRight) {
          nextRight = arr[idx].second;
        }
        idx++;
      }

      if (nextRight == -1) {
        flag = false;
        break;
      }

      latestRight = nextRight;
      cnt++;
    }

    if (!flag || latestRight < M) {
      cout << 0 << "\n";
    } else {
      cout << cnt << "\n";
    }
  }
}
