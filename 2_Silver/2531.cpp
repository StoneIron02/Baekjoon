#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, d, k, c;
  cin >> N >> d >> k >> c;

  vector<int> a(N);
  for(int i = 0; i < N; ++i)
    cin >> a[i];

  vector<int> cnt(d + 1);
  int distinct = 0;

  for(int i = 0; i < k; ++i) {
    if(cnt[a[i]] == 0) ++distinct;
    ++cnt[a[i]];
  }

  int ans = distinct + (cnt[c] == 0);
  for(int i = 1; i < N; ++i) {
    int out = a[i - 1];
    --cnt[out];
    if(cnt[out] == 0) --distinct;

    int in = a[(i + k - 1) % N];
    if(cnt[in] == 0) ++distinct;
    ++cnt[in];

    ans = max(ans, distinct + (cnt[c] == 0));
  }

  cout << ans;
}