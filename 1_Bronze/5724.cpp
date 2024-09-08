#include <iostream>

using namespace std;

int dp[101];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  dp[1] = 1;
  for (int i = 2; i <= 100; i++) {
    dp[i] = dp[i - 1] + i * i;
  }

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    cout << dp[n] << "\n";
  }
}