#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, X;
  cin >> N >> X;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];

  long long sum = 0;
  for (int i = 0; i < X; ++i)
    sum += arr[i];

  long long max_sum = sum;
  int cnt = 1;

  for (int i = X; i < N; ++i) {
    sum += arr[i];
    sum -= arr[i - X];
    if (sum > max_sum) {
      max_sum = sum;
      cnt = 1;
    }
    else if (sum == max_sum) {
      ++cnt;
    }
  }

  if (max_sum == 0) {
    cout << "SAD";
  }
  else {
    cout << max_sum << "\n" << cnt;
  }
}
