#include <algorithm>
#include <iostream>
using namespace std;

int n;
string arr[50];
bool flag[50];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[i] == arr[j].substr(0, arr[i].size())) {
        flag[i] = true;
        break;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (!flag[i]) {
      ++cnt;
    }
  }
  cout << cnt;
}