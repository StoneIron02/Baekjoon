#include <iostream>
#include <cmath>

using namespace std;

int arr[1000][1000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      sum += arr[i][j];
    }
  }

  int start = 0, end = 10'000'000;
  int res;
  while (start <= end) {
    int mid = (start + end) / 2;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt += min(arr[i][j], mid);
      }
    }

    if (cnt >= round(1.0 * sum / 2)) {
      res = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  cout << res;
}