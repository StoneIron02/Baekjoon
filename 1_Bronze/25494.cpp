#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    for (int x = 1; x <= a; x++) {
      for (int y = 1; y <= b; y++) {
        for (int z = 1; z <= c; z++) {
          if (x % y == y % z && y % z == z % x) {
            cnt++;
          }
        }
      }
    }
    cout << cnt << "\n";
  }
}
