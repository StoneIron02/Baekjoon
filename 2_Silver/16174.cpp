#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N;
int board[65][65];
bool visit[65][65];
string dx = "21";
string dy = "12";

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  queue<pii> que;
  visit[1][1] = true;
  que.emplace(1, 1);
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (x == N && y == N) {
      cout << "HaruHaru";
      exit(0);
    }

    for (int i = 0; i < 2; i++) {
      int next_x = x + (dx[i] - '1') * board[x][y];
      int next_y = y + (dy[i] - '1') * board[x][y];

      if (next_x < 1 || next_x > N) continue;
      if (next_y < 1 || next_y > N) continue;
      if (visit[next_x][next_y]) continue;

      if (!visit[next_x][next_y]) {
        visit[next_x][next_y] = true;
        que.emplace(next_x, next_y);
      }
    }
  }

  cout << "Hing";
}