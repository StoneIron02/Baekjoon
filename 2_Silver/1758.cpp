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
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end(), greater<>());

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int tip = arr[i] - i;
    if (tip < 0) {
      tip = 0;
    }
    sum += tip;
  }
  cout << sum;
}