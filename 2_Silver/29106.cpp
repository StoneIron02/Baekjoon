#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int min_diff = arr[k - 1] - arr[0];
  int start_idx = 0;

  for (int i = 1; i <= n - k; i++) {
    int diff = arr[i + k - 1] - arr[i];
    if (diff < min_diff) {
      min_diff = diff;
      start_idx = i;
    }
  }

  for (int i = start_idx; i < start_idx + k; i++) {
    cout << arr[i] << " ";
  }

}
