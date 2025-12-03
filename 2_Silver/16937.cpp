#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int H, W, N;
  cin >> H >> W >> N;
  vector<pair<int, int>> arr(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i].first >> arr[i].second;

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int r1 = 0; r1 < 2; ++r1) {
        for (int r2 = 0; r2 < 2; ++r2) {
          int r1h = r1 ? arr[i].second : arr[i].first;
          int r1w = r1 ? arr[i].first : arr[i].second;
          int r2h = r2 ? arr[j].second : arr[j].first;
          int r2w = r2 ? arr[j].first : arr[j].second;
          if ((r1h + r2h <= H && max(r1w, r2w) <= W) ||
              (r1w + r2w <= W && max(r1h, r2h) <= H) ||
              (r1h + r2h <= W && max(r1w, r2w) <= H) ||
              (r1w + r2w <= H && max(r1h, r2h) <= W))
            ans = max(ans, r1h * r1w + r2h * r2w);
        }
      }
    }
  }
  cout << ans;
}