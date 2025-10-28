#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    long long n;
    cin >> n;
    if (n == 0) break;

    long long tmp = n;
    long long res = 0, base = 1;
    while (tmp > 0) {
      int d = tmp % 10;
      if (d > 4) d--;
      res += d * base;
      base *= 9;
      tmp /= 10;
    }
    cout << n << ": " << res << "\n";
  }
}