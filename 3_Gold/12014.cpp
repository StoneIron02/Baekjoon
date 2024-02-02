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
  int tc = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vector<int> lis;
    for (auto i : arr) {
      auto pos = lower_bound(lis.begin(), lis.end(), i);
      if (pos == lis.end()) {
        lis.push_back(i);
      } else {
        *pos = i;
      }
    }

    cout << "Case #" << tc << "\n";
    cout << (lis.size() >= k) << "\n";
    tc++;
  }
}