#include <iostream>
#include <climits>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;
  int arr[100000];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int minSum = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    int sum = arr[i] * x + arr[i + 1] * x;
    minSum = min(minSum, sum);
  }
  cout << minSum;
}