#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int score1 = 0, score2 = 0;
    while (n--) {
      char a, b;
      cin >> a >> b;
      if (a == 'R') {
        if (b == 'R') {
          continue;
        } else if (b == 'S') {
          score1++;
        } else if (b == 'P') {
          score2++;
        }
      } else if (a == 'S') {
        if (b == 'R') {
          score2++;
        } else if (b == 'S') {
          continue;
        } else if (b == 'P') {
          score1++;
        }
      } else if (a == 'P') {
        if (b == 'R') {
          score1++;
        } else if (b == 'S') {
          score2++;
        } else if (b == 'P') {
          continue;
        }
      }
    }
    if (score1 > score2) {
      cout << "Player 1\n";
    }
    if (score1 < score2) {
      cout << "Player 2\n";
    }
    if (score1 == score2) {
      cout << "TIE\n";
    }
  }
}