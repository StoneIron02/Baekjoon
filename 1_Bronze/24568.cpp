#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int r, s;
  cin >> r >> s;
  int cnt = r * 8 + s * 3 - 28;
  if (cnt < 0) cnt = 0;
  cout << cnt;
}