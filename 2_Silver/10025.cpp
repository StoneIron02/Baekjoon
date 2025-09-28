#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

pii arr[100'000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  long long K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    int g, x;
    cin >> g >> x;
    arr[i] = {x, g};
  }
  
  sort(arr, arr + N);

  long long res = 0, cur = 0;
  int l = 0;
  for (int r = 0; r < N; ++r) {
    cur += arr[r].second;
    while (arr[r].first - arr[l].first > 2 * K) {
      cur -= arr[l].second;
      ++l;
    }
    if (cur > res) res = cur;
  }

  cout << res;
}