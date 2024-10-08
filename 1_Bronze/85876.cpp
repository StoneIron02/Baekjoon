#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int x, l, r;
  cin >> x >> l >> r;

  int res = l;
  int res_d = abs(l - x);
  for (int i = l; i <= r; i++) {
    int d = abs(i - x);
    if (d < res_d) {
      res = i;
      res_d = d;
    }
  }
  cout << res;
}
