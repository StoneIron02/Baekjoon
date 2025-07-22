#include <iostream>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int z;
  cin >> z;
  while (z--) {
    int r_total = 0, g_total = 0, b_total = 0;

    for (int i = 0; i < 10; ++i) {
      int r, g, b;
      cin >> r >> g >> b;
      r_total += r;
      g_total += g;
      b_total += b;
    }

    int r_avg = round(r_total / 10.0);
    int g_avg = round(g_total / 10.0);
    int b_avg = round(b_total / 10.0);

    cout << r_avg << " " << g_avg << " " << b_avg << endl;
  }
}