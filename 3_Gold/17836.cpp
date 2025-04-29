#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int N, M, T;
int board[101][101];
bool visit[101][101];
int dist[101][101];
pii gramPos;
string dx = "0211";
string dy = "1102";

void reset() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      visit[i][j] = false;
      dist[i][j] = -1;
    }
  }
}

void BFS1() {
  reset();
  queue<pii> que;
  visit[1][1] = true;
  dist[1][1] = 0;
  que.emplace(1, 1);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (x == N && y == M) break;

    for (int i = 0; i < 4; i++) {
      int newX = x + (dx[i] - '1');
      int newY = y + (dy[i] - '1');
      if (newX < 1 || newX > N) continue;
      if (newY < 1 || newY > M) continue;
      if (visit[newX][newY]) continue;
      if (board[newX][newY] == 1) continue;

      visit[newX][newY] = true;
      dist[newX][newY] = dist[x][y] + 1;
      que.emplace(newX, newY);
    }
  }
}

void BFS2() {
  reset();
  queue<pii> que;
  visit[1][1] = true;
  dist[1][1] = 0;
  que.emplace(1, 1);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (x == gramPos.first && y == gramPos.second) break;

    for (int i = 0; i < 4; i++) {
      int newX = x + (dx[i] - '1');
      int newY = y + (dy[i] - '1');
      if (newX < 1 || newX > N) continue;
      if (newY < 1 || newY > M) continue;
      if (visit[newX][newY]) continue;
      if (board[newX][newY] == 1) continue;

      visit[newX][newY] = true;
      dist[newX][newY] = dist[x][y] + 1;
      que.emplace(newX, newY);
    }
  }
}

void BFS3() {
  reset();
  queue<pii> que;
  visit[gramPos.first][gramPos.second] = true;
  dist[gramPos.first][gramPos.second] = 0;
  que.emplace(gramPos.first, gramPos.second);

  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (x == N && y == M) break;

    for (int i = 0; i < 4; i++) {
      int newX = x + (dx[i] - '1');
      int newY = y + (dy[i] - '1');
      if (newX < 1 || newX > N) continue;
      if (newY < 1 || newY > M) continue;
      if (visit[newX][newY]) continue;

      visit[newX][newY] = true;
      dist[newX][newY] = dist[x][y] + 1;
      que.emplace(newX, newY);
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> T;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2)
        gramPos = {i, j};
    }
  }

  BFS1();
  int time1 = dist[N][M];
  BFS2();
  int time2 = dist[gramPos.first][gramPos.second];
  BFS3();
  int time3 = dist[N][M];

  int res = 999999999;
  if (time1 != -1 && time1 <= T) {
    res = time1;
  }
  if (time2 != -1 && time3 != -1 && time2 + time3 <= T) {
    res = min(res, time2 + time3);
  }
  if (res == 999999999) {
    cout << "Fail";
  } else {
    cout << res;
  }
}
