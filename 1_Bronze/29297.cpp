#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  while (N--) {
    string s;
    cin >> s;

    int a1 = s[0] - '0';
    int b1 = s[2] - '0';
    int a_win = 0, b_win = 0;

    for (int a2 = 0; a2 <= 9; ++a2) {
      for (int b2 = 0; b2 <= 9; ++b2) {
        int a_total = a1 + a2;
        int b_total = b1 + b2;

        if (a_total > b_total) {
          a_win++;
        } else if (a_total < b_total) {
          b_win++;
        } else {
          if (b1 > a2) {
            b_win++;
          } else if (b1 < a2) {
            a_win++;
          }
        }
      }
    }

    cout << a_win << " " << b_win << '\n';
  }
}