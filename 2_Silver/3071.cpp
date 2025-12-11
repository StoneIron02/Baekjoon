#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    if (n == 0) {
      cout << 0 << "\n";
      continue;
    }

    string res;
    while (n != 0) {
      long long r = (n % 3 + 3) % 3;

      if (r == 0) {
        res.push_back('0');
        n /= 3;
      }
      else if (r == 1) {
        res.push_back('1');
        n = (n - 1) / 3;
      }
      else {
        res.push_back('-');
        n = (n + 1) / 3;
      }
    }

    reverse(res.begin(), res.end());
    cout << res << "\n";
  }
}
