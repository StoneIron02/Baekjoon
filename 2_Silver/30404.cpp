#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  vector<int> arr(N);
  for (int i = 0; i < N; ++i)
    cin >> arr[i];

  int cnt = 0;
  int nextClapTime = -1;

  for (int i = 0; i < N; ++i) {
    if (arr[i] > nextClapTime) {
      cnt++;
      nextClapTime = arr[i] + K;
    }
  }

  cout << cnt << '\n';
}