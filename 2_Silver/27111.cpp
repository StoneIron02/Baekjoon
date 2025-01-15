#include <iostream>

using namespace std;

int cnt[200'001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int res = 0;
  while (N--) {
    int a, b;
    cin >> a >> b;
    if (b == 1 && cnt[a] % 2 == 1) {
      cnt[a] += 1;
      res++;
    }
    else if (b == 0 && cnt[a] % 2 == 0) {
      cnt[a] += 1;
      res++;
    }
    cnt[a]++;
  }
  for (int i = 1; i <= 200'000; i++) {
    if (cnt[i] % 2 == 1) {
      res++;
    }
  }
  cout << res;
}