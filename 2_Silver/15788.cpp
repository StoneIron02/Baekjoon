#include <iostream>

using namespace std;

long long board[501][501];
pair<long long, long long> empty_pos;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 0) empty_pos = {i, j};
    }
  }

  long long target = -1;
  for (int i = 1; i <= N; ++i) {
    if (i == empty_pos.first) continue;
    long long tmp = 0;
    bool valid = true;
    for (int j = 1; j <= N; ++j) {
      tmp += board[i][j];
      if (board[i][j] == 0) {
        valid = false;
        break;
      }
    }
    if (valid) {
      target = tmp;
      break;
    }
  }
  if (target == -1) {
    cout << -1;
    exit(0);
  }

  long long zero_sum = 0;
  for (int i = 1; i <= N; ++i) {
    zero_sum += board[empty_pos.first][i];
  }
  long long M = target - zero_sum;
  board[empty_pos.first][empty_pos.second] = M;

  long long check = 0;
  for (int i = 1; i <= N; ++i) {
    check += board[i][i];
  }
  if (check != target) {
    cout << -1;
    exit(0);
  }

  check = 0;
  for (int i = 1; i <= N; ++i) {
    check += board[i][N - i + 1];
  }
  if (check != target) {
    cout << -1;
    exit(0);
  }

  for (int i = 1; i <= N; ++i) {
    check = 0;
    for (int j = 1; j <= N; ++j) {
      check += board[i][j];
    }
    if (check != target) {
      cout << -1;
      exit(0);
    }
  }

  for (int i = 1; i <= N; ++i) {
    check = 0;
    for (int j = 1; j <= N; ++j) {
      check += board[j][i];
    }
    if (check != target) {
      cout << -1;
      exit(0);
    }
  }

  cout << M;
}