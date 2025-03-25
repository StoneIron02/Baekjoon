#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M, K;
  cin >> N >> M >> K;

  vector<string> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  int answer = 0;
  for (int i = 0; i < N; ++i) {
    int cnt = 0;
    for (int j = 0; j < M; ++j) {
      if (arr[i][j] == '0') {
        cnt++;
        if (cnt >= K) {
          answer++;
        }
      } else {
        cnt = 0;
      }
    }
  }

  cout << answer << endl;
}