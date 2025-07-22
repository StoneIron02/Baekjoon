#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

char board[11][11];
int dist[11][11];
string dx = "0211";
string dy = "1102";
pii startPos;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 1; i <= 10; i++) {
    string str;
    cin >> str;
    for (int j = 1; j <= 10; j++) {
      board[i][j] = str[j - 1];
      if (board[i][j] == 'L') {
        startPos = {i, j};
      }
      dist[i][j] = 100;
    }
  }

  queue<pii> que;
  dist[startPos.first][startPos.second] = 0;
  que.emplace(startPos.first, startPos.second);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (board[x][y] == 'B') {
      cout << dist[x][y] - 1;
      exit(0);
    }

    for (int i = 0; i < 4; i++) {
      int next_x = x + (dx[i] - '1');
      int next_y = y + (dy[i] - '1');
      if (next_x < 1 || next_x > 10) continue;
      if (next_y < 1 || next_y > 10) continue;
      if (board[next_x][next_y] == 'R') continue;
      if (dist[next_x][next_y] != 100) continue;

      dist[next_x][next_y] = dist[x][y] + 1;
      que.emplace(next_x, next_y);
    }
  }
}