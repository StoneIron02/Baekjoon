#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int cheeseCnt;
int beforeCnt;
int t;
bool cheese[101][101];
bool visit[101][101];
string dx = "0211";
string dy = "1102";

void BFS() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      visit[i][j] = false;
    }
  }
  beforeCnt = cheeseCnt;
  t++;

  queue<pair<int, int>> que;
  visit[1][1] = true;
  que.emplace(1, 1);
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      int curDx = x + (dx[i] - '1');
      int curDy = y + (dy[i] - '1');
      if (curDx < 1 || curDx > n) continue;
      if (curDy < 1 || curDy > m) continue;
      if (visit[curDx][curDy]) continue;

      visit[curDx][curDy] = true;
      if (cheese[curDx][curDy]) {
        cheese[curDx][curDy] = false;
        cheeseCnt--;
      } else {
        que.emplace(curDx, curDy);
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> cheese[i][j];
      if (cheese[i][j]) {
        cheeseCnt++;
      }
    }
  }

  while (cheeseCnt > 0) {
    BFS();
  }
  cout << t << "\n";
  cout << beforeCnt << "\n";
}
