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
  for (auto& i : arr) {
    cin >> i;
  }
  sort(arr.begin(), arr.end());
  cout << arr[n - 1];
}