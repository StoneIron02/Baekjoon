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
  vector<long long> arr(N);
  for (auto& i : arr) {
    cin >> i;
  }
  sort(arr.begin(), arr.end());
  long long res = 0;
  for (int i = 1; i < N; i++) {
    res += arr[i] - arr[i - 1];
  }
  res += arr[N - 1] - arr[0];
  cout << res;
}
