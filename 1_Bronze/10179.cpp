#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while (t--) {
    double origin;
    cin >> origin;
    double result = origin * 0.8;
    cout << "$" << fixed << setprecision(2) << result << "\n";
  }
}
