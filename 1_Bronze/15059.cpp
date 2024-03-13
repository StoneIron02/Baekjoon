#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int c, b, p;
  cin >> c >> b >> p;
  int cr, br, pr;
  cin >> cr >> br >> pr;
  int sum = 0;
  sum += cr - c > 0 ? cr - c : 0;
  sum += br - b > 0 ? br - b : 0;
  sum += pr - p > 0 ? pr - p : 0;
  cout << sum;
}