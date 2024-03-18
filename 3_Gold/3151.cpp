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
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  long long cnt = 0;
  for(int i = 0; i < n - 2; i++) {
    for(int j = i + 1; j < n - 1; j++) {
      int k = 0 - arr[i] - arr[j];
      cnt += upper_bound(arr.begin() + j + 1, arr.end(), k) - lower_bound(arr.begin() + j + 1, arr.end(), k);
    }
  }
  cout << cnt;
}