#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int lastTime = 0;
  int maxLen = 0;
  for (int i = 0; i < N; i++) {
    int T, M;
    cin >> T >> M;
    if (M == 1) {
      int time = T - lastTime;
      maxLen = max(maxLen, time);
      lastTime = T;
    }
  }
  cout << maxLen;
}