#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long long> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  sort(x.begin(), x.end());

  long long prefix_sum = 0;
  long long each_sum = 0;
  for (int i = 0; i < n; ++i) {
    each_sum += x[i] * i - prefix_sum;
    prefix_sum += x[i];
  }

  long long res = each_sum * 2;
  cout << res;
}