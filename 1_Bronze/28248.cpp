#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int p, c;
  cin >> p >> c;
  int res = 0;
  res += p * 50;
  res -= c * 10;
  if (p > c) {
    res += 500;
  }
  cout << res;
}