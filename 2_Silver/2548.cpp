#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> arr(N);
  for (auto &i : arr) cin >> i;
  ranges::sort(arr);
  cout << arr[N / 2 - (N % 2 == 0)] << "\n";
}
