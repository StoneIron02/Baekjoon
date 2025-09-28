#include <iostream>
#include <climits>
using namespace std;

int ans = INT_MAX;
string flag[6];

void row() {
  for (char up = 'A'; up <= 'Z'; ++up) {
    for (char mid = 'A'; mid <= 'Z'; ++mid) {
      if (up == mid) continue;
      for (char down = 'A'; down <= 'Z'; ++down) {
        if (mid == down) continue;
        int changes = 0;

        // 위
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 9; j++) {
            if (flag[i][j] != up) changes++;
          }
        }

        // 중간
        for (int i = 2; i < 4; i++) {
          for (int j = 0; j < 9; j++) {
            if (flag[i][j] != mid) changes++;
          }
        }

        // 아래
        for (int i = 4; i < 6; i++) {
          for (int j = 0; j < 9; j++) {
            if (flag[i][j] != down) changes++;
          }
        }

        ans = min(ans, changes);
      }
    }
  }
}

void col() {
  for (char left = 'A'; left <= 'Z'; ++left) {
    for (char mid = 'A'; mid <= 'Z'; ++mid) {
      if (left == mid) continue;
      for (char right = 'A'; right <= 'Z'; ++right) {
        if (mid == right) continue;
        int changes = 0;

        // 왼쪽
        for (int i = 0; i < 6; i++) {
          for (int j = 0; j < 3; j++) {
            if (flag[i][j] != left) changes++;
          }
        }

        // 중간
        for (int i = 0; i < 6; i++) {
          for (int j = 3; j < 6; j++) {
            if (flag[i][j] != mid) changes++;
          }
        }

        // 오른쪽
        for (int i = 0; i < 6; i++) {
          for (int j = 6; j < 9; j++) {
            if (flag[i][j] != right) changes++;
          }
        }

        ans = min(ans, changes);
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (auto& i : flag) {
    cin >> i;
  }

  row();
  col();

  cout << ans << "\n";
}