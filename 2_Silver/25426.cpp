#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> pll;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;

  vector<pll> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }
  
  ranges::sort(arr, [](const pll& lhs, const pll& rhs) {
      return lhs.first > rhs.first;
  });

  long long res = 0;
  for (int i = 0; i < N; ++i) {
    long long x = N - i;
    res += arr[i].first * x + arr[i].second;
  }

  cout << res;
}