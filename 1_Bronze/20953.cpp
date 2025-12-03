#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    long long n = a + b;
    long long res = 1LL * n * n * (n - 1) / 2;
    cout << res << "\n";
  }
}