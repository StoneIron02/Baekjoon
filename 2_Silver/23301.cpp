#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, T;
  cin >> N >> T;
  for (int i = 0; i < N; ++i) {
    int K;
    cin >> K;
    for (int j = 0; j < K; ++j) {
      int S, E;
      cin >> S >> E;
      for (int t = S; t < E; ++t) {
        ++arr[t];
      }
    }
  }

  int sum = 0;
  for (int t = 0; t < T; ++t) {
    sum += arr[t];
  }
  int max_sum = sum;
  int max_start = 0;
  for (int start = 1; start <= 1001 - T; ++start) {
    sum = sum - arr[start - 1] + arr[start + T - 1];
    if (sum > max_sum) {
      max_sum = sum;
      max_start = start;
    }
  }
  cout << max_start << " " << max_start + T;
}