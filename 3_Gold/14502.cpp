#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int origin[9][9];
int matrix[9][9];
bool visit[9][9];
vector<pii> emptyPos;
string dx = "0211";
string dy = "1102";
int maxCnt = -1;

void BFS(pii s) {
  queue<pii> q;
  visit[s.first][s.second] = true;
  q.push(s);

  while (!q.empty()) {
    auto top = q.front();
    q.pop();

    for (int i = 0; i < dx.size(); i++) {
      int curDx = top.first + (dx[i] - '1');
      int curDy = top.second + (dy[i] - '1');

      if (curDx < 1 || curDx > n) continue;
      if (curDy < 1 || curDy > m) continue;
      if (matrix[curDx][curDy] == 1) continue;
      if (visit[curDx][curDy]) continue;

      visit[curDx][curDy] = true;
      matrix[curDx][curDy] = 2;
      q.push({curDx, curDy});
    }
  }
}

void CreateWall(int cur, int before) {
  if (cur == 3) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        matrix[i][j] = origin[i][j];
        visit[i][j] = false;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (matrix[i][j] == 2 && !visit[i][j])
          BFS({i, j});
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (matrix[i][j] == 0)
          cnt++;
      }
    }
    maxCnt = max(maxCnt, cnt);
    return;
  }

  for (int i = before + 1; i < emptyPos.size(); i++) {
    origin[emptyPos[i].first][emptyPos[i].second] = 1;
    CreateWall(cur + 1, i);
    origin[emptyPos[i].first][emptyPos[i].second] = 0;
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> origin[i][j];
      if (origin[i][j] == 0)
        emptyPos.push_back({i, j});
    }
  }
  CreateWall(0, -1);
  cout << maxCnt;
}