#include <iostream>

using namespace std;

int pond[51][51];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int R, C;
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> pond[i][j];
    }
  }

  int maxDepth = -1;
  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (pond[i][j] == 0) continue;

      for (int d = 0; d < 8; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];

        if (ni >= 0 && ni < R && nj >= 0 && nj < C && pond[i][j] == pond[ni][nj]) {
          maxDepth = max(maxDepth, pond[i][j]);
        }
      }
    }
  }

  cout << maxDepth << endl;
  return 0;
}