#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int g = a[0];
  for (int i = 1; i < n; ++i)
    g = gcd(g, a[i]);

  vector<int> res;
  for (int i = 1; i * i <= g; ++i) {
    if (g % i == 0) {
      res.push_back(i);
      if (i * i != g) res.push_back(g / i);
    }
  }

  ranges::sort(res);
  for (auto& x : res)
    cout << x << "\n";
}