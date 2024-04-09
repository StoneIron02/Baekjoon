#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int maxVal = 1;
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& i : arr) {
    cin >> i;
  }
  sort(arr.begin(), arr.end(), greater());
  int day = 1;
  for (auto& i : arr) {
    maxVal = max(maxVal, day + i);
    day++;
  }
  cout << maxVal + 1;
}