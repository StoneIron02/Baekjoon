#include <iostream>
#include <algorithm>

using namespace std;

int arr[100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << (arr[n - 1] - arr[0]) * 2 << "\n";
  }
}