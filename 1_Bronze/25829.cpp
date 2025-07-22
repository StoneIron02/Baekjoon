#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int tot1 = 0, tot2 = 0;
  int sungu_tot1 = 0, sungu_tot2 = 0;

  for (int i = 0; i < n; ++i) {
    int e, v1, v2;
    cin >> e >> v1 >> v2;

    tot1 += v1;
    tot2 += v2;

    if (v1 > v2) {
      sungu_tot1 += e;
    } else {
      sungu_tot2 += e;
    }
  }

  int win = 0, win_sungu = 0;

  if (tot1 > tot2) {
    win = 1;
  } else if (tot2 > tot1) {
    win = 2;
  }

  if (sungu_tot1 > sungu_tot2) {
    win_sungu = 1;
  } else if (sungu_tot2 > sungu_tot1) {
    win_sungu = 2;
  }

  if (win == 1 && win_sungu == 1) {
    cout << 1;
  } else if (win == 2 && win_sungu == 2) {
    cout << 2;
  } else {
    cout << 0;
  }
}