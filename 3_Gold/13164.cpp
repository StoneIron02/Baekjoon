#include <iostream>
#include <algorithm>
using namespace std;

int arr[300'001];
pair<int, int> diff[300'000];
bool cut[300'000];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < N - 1; i++) {
    diff[i] = {arr[i + 1] - arr[i], i};
  }
  sort(diff, diff + N, greater<>());
  for (int i = 0; i < K - 1; i++) {
    cut[diff[i].second] = true;
  }
  int start = 0;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (cut[i]) {
      int end = i;
      sum += arr[end] - arr[start];
      start = i + 1;
    }
  }
  sum += arr[N - 1] - arr[start];
  cout << sum;
}
