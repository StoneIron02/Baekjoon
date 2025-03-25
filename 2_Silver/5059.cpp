#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());

    int max_discount = 0;
    for (int i = 2; i < n; i += 3) {
      max_discount += arr[i];
    }
    cout << max_discount << "\n";
  }
}