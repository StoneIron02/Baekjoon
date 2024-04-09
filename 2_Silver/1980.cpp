#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m, t;
  cin >> n >> m >> t;

  int minLeft = t;
  int maxCnt = 0;

  if (n > m) {
    int tmp = n;
    n = m;
    m = tmp;
  }
  for (int i = 0; i * n <= 10000; i++) {
    int left = t - i * n;
    for (int j = 0; j * m <= left; j++) {
      int left2 = left - j * m;
      int cnt = i + j;
      if (left2 <= minLeft && maxCnt < cnt) {
        minLeft = left2;
        maxCnt = cnt;
      }
    }
  }
  cout << maxCnt << " " << minLeft;
}