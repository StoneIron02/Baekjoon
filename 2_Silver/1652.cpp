#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  vector<string> board(N);
  for (auto& i : board) {
    cin >> i;
  }
  vector<string> board_vertical(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board_vertical[j] += board[i][j];
    }
  }

  int cnt_hor = 0, cnt_ver = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (board[i][j - 1] == '.' && board[i][j] == '.') {
        cnt_hor++;
        while (board[i][j] == '.') j++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 1; j < N; j++) {
      if (board_vertical[i][j - 1] == '.' && board_vertical[i][j] == '.') {
        cnt_ver++;
        while (board_vertical[i][j] == '.') j++;
      }
    }
  }
  cout << cnt_hor << " " << cnt_ver;
}
