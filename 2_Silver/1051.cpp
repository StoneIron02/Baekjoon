#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (int i = 0; i < n; ++i)
    cin >> board[i];
  int max_size = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 1; i + k < n && j + k < m; ++k) {
        if (board[i][j] == board[i][j + k] && board[i][j] == board[i + k][j] && board[i][j] == board[i + k][j + k]) {
          max_size = max(max_size, (k + 1) * (k + 1));
        }
      }
    }
  }
  cout << max_size;
}
