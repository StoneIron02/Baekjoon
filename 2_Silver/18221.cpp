#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<vector<int>> a(N, vector<int>(N));
  int sr, sc, pr, pc;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2) sr = i, sc = j;
      if (a[i][j] == 5) pr = i, pc = j;
    }
  }
  int dr = sr - pr, dc = sc - pc;
  double dist = sqrt(1.0 * dr * dr + 1.0 * dc * dc);
  if (dist < 5) {
    cout << 0;
    return 0;
  }
  if (sr == pr) {
    int cnt = 0;
    for (int c = min(sc, pc) + 1; c < max(sc, pc); c++)
      if (a[sr][c] == 1) cnt++;
    cout << (cnt >= 3);
    return 0;
  }
  if (sc == pc) {
    int cnt = 0;
    for (int r = min(sr, pr) + 1; r < max(sr, pr); r++)
      if (a[r][sc] == 1) cnt++;
    cout << (cnt >= 3);
    return 0;
  }
  int r1 = min(sr, pr), r2 = max(sr, pr);
  int c1 = min(sc, pc), c2 = max(sc, pc);
  int cnt = 0;
  for (int i = r1; i <= r2; i++)
    for (int j = c1; j <= c2; j++)
      if (a[i][j] == 1) cnt++;
  cout << (cnt >= 3);
}