#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int g, c, e;
    cin >> g >> c >> e;
    if (g == 1) {
      int cnt = (e - c) * 1;
      if (cnt < 0) cnt = 0;
      cout << cnt << "\n";
    }
    if (g == 2) {
      int cnt = (e - c) * 3;
      if (cnt < 0) cnt = 0;
      cout << cnt << "\n";
    }
    if (g == 3) {
      int cnt = (e - c) * 5;
      if (cnt < 0) cnt = 0;
      cout << cnt << "\n";
    }
  }
}