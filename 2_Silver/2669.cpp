#include <iostream>
using namespace std;

bool board[101][101];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  for (int r = 0; r < 4; ++r) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int x = x1; x < x2; ++x) {
      for (int y = y1; y < y2; ++y) {
        board[x][y] = true;
      }
    }
  }

  int cnt = 0;
  for (int x = 1; x <= 100; ++x) {
    for (int y = 1; y <= 100; ++y) {
      if (board[x][y]) ++cnt;
    }
  }
  cout << cnt;
}
