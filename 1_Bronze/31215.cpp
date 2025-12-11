#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (n <= 2) cout << 1 << "\n";
    else cout << 3 << "\n";
  }
}
