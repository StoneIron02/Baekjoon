#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  int maxCnt = 0;
  int cnt = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cnt += a;
    cnt -= b;
    maxCnt = max(maxCnt, cnt);
  }
  int remain = max(maxCnt - k, 0);
  cout << remain;
}