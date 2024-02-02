#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int jinjuCost = -1;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    cin >> arr[i];
    if (str == "jinju") {
      jinjuCost = arr[i];
    }
  }
  cout << jinjuCost << "\n";
  sort(arr, arr + n);
  auto p = upper_bound(arr, arr + n, jinjuCost) - arr;
  cout << n - p;
}