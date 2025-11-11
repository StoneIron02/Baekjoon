#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<double> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  ranges::sort(a);
  double ans = a.back();
  for (int i = 0; i < N - 1; ++i) ans += a[i] / 2;
  cout << fixed << setprecision(6) << ans;
}
