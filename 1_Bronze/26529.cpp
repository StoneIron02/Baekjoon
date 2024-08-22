#include <iostream>
using namespace std;

long long dp[46];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= 45; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }
}
