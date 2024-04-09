#include <iostream>
using namespace std;

int d, p;
int divVal = 1;
long long maxVal = -1;

void solve(int cur, long long val, int before) {
  if (cur == p) {
    maxVal = max(maxVal, val);
    return;
  }

  for (int i = before; i <= 9; i++) {
    long long res = val * i;
    if (res / divVal > 0)
      break;
    solve(cur + 1, res, i);
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> d >> p;
  for (int i = 0; i < d; i++) {
    divVal *= 10;
  }
  solve(0, 1, 2);
  cout << maxVal;
}