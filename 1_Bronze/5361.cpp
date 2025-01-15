#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  double price[5] {350.34, 230.90, 190.55, 125.30, 180.90};
  int T;
  cin >> T;
  while (T--) {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
      int cnt;
      cin >> cnt;
      sum += cnt * price[i];
    }
    cout << "$" << fixed << setprecision(2) << sum << "\n";
  }
}