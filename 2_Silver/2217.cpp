#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int arr[100'000];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N, greater<>());
  int maxVal = 0;
  for (int i = 0; i < N; i++) {
    maxVal = max(maxVal, (i + 1) * arr[i]);
  }
  cout << maxVal;
}