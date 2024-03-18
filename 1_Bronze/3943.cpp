#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int max_n = n;
    while (n != 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else {
        n = n * 3 + 1;
      }
      max_n = max(max_n, n);
    }
    cout << max_n << "\n";
  }
}