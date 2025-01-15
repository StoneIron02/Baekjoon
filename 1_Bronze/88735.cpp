#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    long long x, w;
    cin >> x >> w;
    long long cnt = 0;
    while (x < w) {
      x *= 2;
      cnt++;
    }
    cout << cnt << "\n";
  }
}