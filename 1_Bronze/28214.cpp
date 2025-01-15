#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k, p;
  int res = 0;
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    int cnt0 = 0;
    for (int j = 0; j < k; j++) {
      int num;
      cin >> num;
      if (num == 0) cnt0++;
    }
    if (cnt0 < p) {
      res++;
    }
  }
  cout << res;
}