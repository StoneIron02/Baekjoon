#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long fun(long long a, long long d, long long n) {
  return n * (2 * a + (n - 1) * d) / 2;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int N, D;
    cin >> N >> D;
    if (N == 0 && D == 0) break;

    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](auto& l, auto& r) {
      if (l.first == r.first)
        return l.second < r.second;
      return l.first > r.first;
    });

    if (N == 1) {
      long long res = fun(arr[0].first, -arr[0].second, D);
      cout << res << "\n";
      continue;
    }

    vector<long long> results;
    for (int i = 0; i * 2 <= D; i++) {
      long long tmp0 = arr[0].first;
      long long tmp1 = arr[1].first;
      long long res = 1LL * i * (tmp0 + tmp1) + fun(arr[0].first, -arr[0].second, D - 2 * i);
      results.push_back(res);
    }
    cout << *max_element(results.begin(), results.end()) << "\n";
  }
}
