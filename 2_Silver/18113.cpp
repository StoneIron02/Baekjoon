#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;
  vector<int> L(N);
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }

  int left = 1, right = 1e9, ans = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    int cnt = 0;
    
    for (auto& len : L) {
      if (len <= K) continue;
      int good_kimbab = 0;
      if (len >= 2 * K) good_kimbab = len - 2 * K;
      else good_kimbab = len - K;
      if (good_kimbab >= mid) cnt += good_kimbab / mid;
    }
    
    if (cnt >= M) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans;
}