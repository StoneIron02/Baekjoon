#include <iostream>
#include <algorithm>

using namespace std;

int arr[15000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  int i = 0, j = 1, cnt = 0;
  while (i < n - 1) {
    if (arr[i] + arr[j] < m) {
      j++;
      continue;
    } else if (arr[i] + arr[j] == m) {
      cnt++;
    }
    i++;
    j = i + 1;
  }
  cout << cnt;
}