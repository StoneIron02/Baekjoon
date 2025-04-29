#include <iostream>
using namespace std;

int N, M, K;
char board[301][301];
bool win[301][301];

void solve() {
  for (int i = N; i >= 1; i--) {
    for (int j = M; j >= 1; j--) {
      if (board[i][j] == '#') continue;
      if (win[i][j]) continue;

      if (i - 1 >= 1)
        win[i - 1][j] = true;
      if (j - 1 >= 1)
        win[i][j - 1] = true;
      for (int k = 1; k <= K; k++) {
        if (i - k >= 1 && j - k >= 1)
          win[i - k][j - k] = true;
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> board[i][j];
    }
  }

  solve();

  int Q;
  cin >> Q;
  while (Q--) {
    int a, b;
    cin >> a >> b;
    cout << (win[a][b] ? "First" : "Second") << "\n";
  }
}
