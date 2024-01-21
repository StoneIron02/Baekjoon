#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  double before, after;
  cin >> before;
  while (true) {
    cin >> after;
    if (after == 999) break;
    cout << fixed << setprecision(2) << after - before << "\n";
    before = after;
  }
}