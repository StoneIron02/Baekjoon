#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int N, M;
int board1[31][31];
int board2[31][31];
bool visit[31][31];
pii changedPos = {-1, -1};
string dx = "0211";
string dy = "1102";

void BFS() {
  queue<pii> que;
  visit[changedPos.first][changedPos.second] = true;
  que.emplace(changedPos.first, changedPos.second);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int curDx = x + (dx[i] - '1');
      int curDy = y + (dy[i] - '1');
      if (curDx < 1 || curDx > N) continue;
      if (curDy < 1 || curDy > M) continue;
      if (visit[curDx][curDy]) continue;
      if (board1[x][y] != board1[curDx][curDy]) continue;

      visit[curDx][curDy] = true;
      que.emplace(curDx, curDy);
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> board1[i][j];
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> board2[i][j];
      if (board1[i][j] != board2[i][j]) changedPos = {i, j};
    }
  }

  if (changedPos.first == -1 && changedPos.second == -1) {
    cout << "YES";
    return 0;
  }

  BFS();

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (visit[i][j] && board2[i][j] != board2[changedPos.first][changedPos.second]) {
        cout << "NO";
        return 0;
      }
      if (!visit[i][j] && board1[i][j] != board2[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
