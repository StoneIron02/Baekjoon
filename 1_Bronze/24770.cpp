#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    int sel_a = 0, sel_b = 0;
    double sel_ratio = 1e9;

    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      if (a > m) continue;

      double ratio = (double)b / a;
      if (ratio < sel_ratio || (ratio == sel_ratio && a > sel_a)) {
        sel_ratio = ratio;
        sel_a = a;
        sel_b = b;
      }
    }

    if (sel_a == 0) {
      cout << "No suitable tickets offered\n";
    } else {
      cout << "Buy " << sel_a << " tickets for $" << sel_b << "\n";
    }
  }
}