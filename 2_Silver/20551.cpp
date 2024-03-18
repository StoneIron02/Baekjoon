#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    if (binary_search(arr.begin(), arr.end(), num)) {
      cout << lower_bound(arr.begin(), arr.end(), num) - arr.begin() << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}