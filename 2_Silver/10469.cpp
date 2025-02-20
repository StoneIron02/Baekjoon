#include <iostream>

using namespace std;
typedef pair<int, int> pii;

string board[8];
pii queens[8];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (auto & i : board) {
    cin >> i;
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == '*') {
        queens[i] = {i, j};
      }
    }
  }

  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      int r1 = queens[i].first,  c1 = queens[i].second;
      int r2 = queens[j].first,  c2 = queens[j].second;
      if (r1 == r2 || c1 == c2 || (abs(r1 - r2) == abs(c1 - c2))) {
        cout << "invalid";
        return 0;
      }
    }
  }

  cout << "valid";
}