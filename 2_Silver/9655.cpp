#include <iostream>
using namespace std;

int dp[1001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = min(dp[i - 1], dp[i - 3]) + 1;
  }

  if (dp[n] % 2 == 1) {
    cout << "SK";
  } else {
    cout << "CY";
  }
}