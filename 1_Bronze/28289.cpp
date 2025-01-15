#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int p;
  cin >> p;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
  while (p--) {
    int gp, cp, np;
    cin >> gp >> cp >> np;
    if (gp == 1) cnt4++;
    else {
      if (cp == 1 || cp == 2) cnt1++;
      else if (cp == 3) cnt2++;
      else cnt3++;
    }
  }
  cout << cnt1 << "\n";
  cout << cnt2 << "\n";
  cout << cnt3 << "\n";
  cout << cnt4 << "\n";
}