#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, q;
pair<long long, long long> arr[100'000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }
  sort(arr, arr + n);

  for (int i = 0; i < q; i++) {
    long long u, v, x, y;
    cin >> u >> v >> x >> y;
    int begin = lower_bound(arr, arr + n, make_pair(u, LLONG_MIN)) - arr;
    int end = upper_bound(arr, arr + n, make_pair(v, LLONG_MAX)) - arr;

    int cnt = 0;
    for (int j = begin; j < end; j++) {
      if (x <= arr[j].second && arr[j].second <= y) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}