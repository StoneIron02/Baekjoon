#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  while (cin >> n && n != 0) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    bool flag = true;
    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] > 200) {
        flag = false;
        break;
      }
    }
    if ((1422 - arr[n - 1]) * 2 > 200) {
      flag = false;
    }
    cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
  }

}