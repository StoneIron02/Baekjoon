#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    char board[3][3];
    for (int i = 0; i < 3; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < 3; j++) {
        board[i][j] = str[j];
      }
    }

    char my;
    cin >> my;
    bool flag = false;

    // --- test
    for (int i = 0; i < 3; i++) {
      int myCnt = 0;
      int blankCnt = 0;
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == my) {
          myCnt++;
        } else if (board[i][j] == '-') {
          blankCnt++;
        }
      }
      if (myCnt == 2 && blankCnt == 1) {
        for (int j = 0; j < 3; j++) {
          board[i][j] = my;
        }
        flag = true;
        break;
      }
    }

    // | test
    if (!flag) {
      for (int j = 0; j < 3; j++) {
        int myCnt = 0;
        int blankCnt = 0;
        for (int i = 0; i < 3; i++) {
          if (board[i][j] == my) {
            myCnt++;
          } else if (board[i][j] == '-') {
            blankCnt++;
          }
        }
        if (myCnt == 2 && blankCnt == 1) {
          for (int i = 0; i < 3; i++) {
            board[i][j] = my;
          }
          flag = true;
          break;
        }
      }
    }

    // cross test
    if (!flag) {
      int myCnt = 0;
      int blankCnt = 0;
      for (int i = 0; i < 3; i++) {
        if (board[i][i] == my) {
          myCnt++;
        } else if (board[i][i] == '-') {
          blankCnt++;
        }
      }
      if (myCnt == 2 && blankCnt == 1) {
        for (int i = 0; i < 3; i++) {
          board[i][i] = my;
        }
        flag = true;
      }
    }

    if (!flag) {
      board[0][2] = my;
      board[1][1] = my;
      board[2][0] = my;
    }

    cout << "Case " << T << ":\n";
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << board[i][j];
      }
      cout << "\n";
    }
  }
}