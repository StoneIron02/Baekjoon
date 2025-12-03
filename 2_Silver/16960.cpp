#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;

  vector<vector<int>> arr(N);
  for (int i = 0; i < N; ++i) {
    int k;
    cin >> k;
    arr[i].resize(k);
    for (int j = 0; j < k; ++j) cin >> arr[i][j];
  }

  for (int s = 0; s < N; ++s) {
    vector<int> lamp(M + 1, 0);
    for (int i = 0; i < N; ++i) {
      if (i == s) continue;
      for (int l : arr[i]) lamp[l] = 1;
    }
    bool flag = true;
    for (int i = 1; i <= M; ++i) {
      if (!lamp[i]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
}