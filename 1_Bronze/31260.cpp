#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  long long x, y, d;
  cin >> x >> y >> d;
  long long l = x * 100 + y;
  long long d1 = (l - d * 2) / 4;
  long long d2 = d1 + d;
  cout << d2 / 100 << " " << d2 % 100 << "\n";
  cout << d1 / 100 << " " << d1 % 100 << "\n";
}
