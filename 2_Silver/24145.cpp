#include <iostream>
#include <ranges>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;

  unordered_map<long long, int> cnt;

  for (int i = 0; i < n; ++i) {
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    for (int x = p; x <= r; ++x) {
      for (int y = q; y <= s; ++y) {
        long long key = static_cast<long long>(x) << 32 | static_cast<unsigned int>(y);
        ++cnt[key];
      }
    }
  }

  int mx = 0;
  long long area = 0;

  for (auto &val : cnt | views::values) {
    if (val > mx) {
      mx = val;
      area = 1;
    }
    else if (val == mx) {
      ++area;
    }
  }

  cout << mx << "\n";
  cout << area << "\n";
}
