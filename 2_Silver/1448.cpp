#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<long long> arr(N);
  for (int i = 0; i < N; ++i) cin >> arr[i];
  ranges::sort(arr, greater());

  for (int i = 0; i + 2 < N; ++i) {
    if (arr[i] < arr[i + 1] + arr[i + 2]) {
      cout << arr[i] + arr[i + 1] + arr[i + 2];
      return 0;
    }
  }
  cout << -1;
}
