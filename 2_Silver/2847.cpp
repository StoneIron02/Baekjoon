#include <iostream>

using namespace std;

int arr[100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int res = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i + 1] - 1 < arr[i]) {
      res += arr[i] - arr[i + 1] + 1;
      arr[i] = arr[i + 1] - 1;
    }
  }
  cout << res;
}