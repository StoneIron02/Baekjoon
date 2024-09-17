#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<int> ml(N);
  for (int& i : ml) {
    cin >> i;
  }

  int left = 1, right = INT_MAX;
  int res = 0;
  while (left <= right) {
    int mid = (1LL * left + right) / 2;

    int cnt = 0;
    for (int& i : ml) {
      cnt += i / mid;
    }

    if (cnt >= K) {
      res = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << res;
}