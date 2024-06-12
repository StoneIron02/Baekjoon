#include <iostream>

using namespace std;

long long dp[10001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int p;
    long long q;
    cin >> p >> q;

    dp[1] = dp[2] = 1;
    for (int i = 3; i <= p; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % q;
    }

    cout << "Case #" << t << ": " << (dp[p] % q) << "\n";
  }
}