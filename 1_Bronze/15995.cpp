#include <iostream>

using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int gcd = extendedGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}

int modularInverse(int a, int m) {
  int x, y;
  int gcd = extendedGCD(a, m, x, y);
  if (gcd != 1) {
    return -1;
  } else {
    return (x % m + m) % m;
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, m;
  cin >> a >> m;
  cout << modularInverse(a, m);
}