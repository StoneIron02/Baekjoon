#include <iostream>
using namespace std;

int N;
int M;
int grant[2][3];
int cnt = 0;

void compute_M(int cur, int curM, int beforeJ) {
  if (cur == N) {
    if (curM >= M) cnt++;
    return;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if (beforeJ == j) {
        compute_M(cur + 1, curM + grant[i][j] / 2, j);
      } else {
        compute_M(cur + 1, curM + grant[i][j], j);
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> N >> M;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> grant[i][j];
    }
  }
  compute_M(0, 0, -1);
  cout << cnt;
}
