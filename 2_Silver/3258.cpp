#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, Z, M;
  cin >> N >> Z >> M;
  vector<bool> block(N + 1, false);
  for (int i = 0; i < M; ++i) {
    int x;
    cin >> x;
    block[x] = true;
  }

  for (int K = 1; K <= N; ++K) {
    int cur = 1;
    vector<int> visited(N + 1, 0);
    bool flag = true;
    while (true) {
      if (cur == Z) break;
      if (visited[cur]) { flag = false; break; }
      visited[cur] = 1;

      cur += K;
      if (cur > N) cur -= N;
      if (block[cur]) { flag = false; break; }
    }
    if (flag) {
      cout << K;
      return 0;
    }
  }
}
