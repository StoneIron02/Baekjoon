#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  int res = 0;
  while (N--) {
    int a, b, c;
    cin >> a >> b >> c;
    int prize = 0;
    if (a == b && b == c) prize = 10000 + a * 1000;
    else if (a == b || a == c) prize = 1000 + a * 100;
    else if (b == c) prize = 1000 + b * 100;
    else prize = max({a, b, c}) * 100;
    res = max(res, prize);
  }
  cout << res;
}