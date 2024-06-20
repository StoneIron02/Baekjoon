#include <iostream>
#include <climits>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    int dist = y - x;
    if (dist < 4) {
      cout << dist << "\n";
      continue;
    }

    int cnt = 1;
    for (long long i = 2; i * i < LLONG_MAX; i++) {
      if (dist <= i * i) {
        if (dist <= (i - 1) * (i - 1) + (i - 1)) {
          cout << cnt + 1 << "\n";
        } else {
          cout << cnt + 2 << "\n";
        }
        break;
      }
      cnt += 2;
    }
  }
}