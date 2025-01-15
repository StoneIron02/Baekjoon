#include <iostream>

using namespace std;

int cnt[50001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int l1, r1, l2, r2, k;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  for (int i = l1; i <= r1; i++) {
    cnt[i]++;
  }
  for (int i = l2; i <= r2; i++) {
    cnt[i]++;
  }
  cnt[k]--;

  int res = 0;
  for (int i = 1; i <= 50000; i++) {
    if (cnt[i] == 2) {
      res++;
    }
  }
  cout << res;
}