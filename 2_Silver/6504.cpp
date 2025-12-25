#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> dp = {0, 1, 2};
  while (dp.back() <= 25000)
    dp.push_back(dp[dp.size() - 1] + dp[dp.size() - 2]);

  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;

    vector<int> b(dp.size(), 0);
    for (int i = dp.size() - 1; i >= 1; --i) {
      if (dp[i] <= x) {
        b[i] = 1;
        x -= dp[i];
        if (i > 1) b[i - 1] = 0;
      }
    }

    int y = 0;
    for (int i = 2; i < b.size(); ++i)
      if (b[i]) y += dp[i - 1];

    cout << y << '\n';
  }
}
