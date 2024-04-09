#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  double arr[n];
  for (auto& i : arr) {
    cin >> i;
  }
  sort(arr, arr + n);

  double sum1 = 0;
  for (int i = k; i < n - k; i++) {
    sum1 += arr[i];
  }
  cout << fixed << setprecision(2) << sum1 / (n - k - k) + 0.00000001 << "\n";

  for (int i = 0; i < k; i++) {
    arr[i] = arr[k];
  }
  for (int i = n - k; i < n; i++) {
    arr[i] = arr[n - k - 1];
  }
  double sum2 = 0;
  for (auto& i : arr) {
    sum2 += i;
  }
  cout << fixed << setprecision(2) << sum2 / n + 0.00000001 << "\n";
}