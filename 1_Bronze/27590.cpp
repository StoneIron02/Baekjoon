#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int ds, ys, dm, ym;
  cin >> ds >> ys;
  cin >> dm >> ym;

  for (int x = 1; x <= 5000; ++x) {
    if ((x + ds) % ys == 0 && (x + dm) % ym == 0) {
      cout << x;
      break;
    }
  }
  
}
