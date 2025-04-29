#include <iostream>
using namespace std;

int N, M, K;
bool exist[2001][2001];
bool visit[2001][2001];

void Hire() {
  int rightmost = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = rightmost; j <= M; j++) {
      if (visit[i][j]) break;
      visit[i][j] = true;
      if (exist[i][j]) {
        exist[i][j] = false;
        rightmost = j;
        K--;
      }
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
      char c;
      cin >> c;
      if (c == 'C') {
        exist[i][j] = true;
        K++;
      }
    }
  }

  int cnt = 0;
  while (K > 0) {
    cnt++;
    Hire();
  }

  cout << cnt;
}
