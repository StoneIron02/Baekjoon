#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  long long MOD = 1'000'000'007;
  long long f[3];
  f[0] = f[1] = f[2] = 1;
  for (int i = 3; i <= n; i++) {
    f[0] = f[1];
    f[1] = f[2];
    f[2] = (f[1] + f[0]) % MOD;
  }
  cout << f[2] << " " << (n - 2) << "\n";
}