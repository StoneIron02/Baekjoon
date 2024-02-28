#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int cur = 0;
  int d = 1;
  int n;
  cin >> n;
  while (n--) {
    if (d == 1) {
      if (cur == 5) {
        d = -1;
      }
    }
    else if (d == -1) {
      if (cur == 1) {
        d = 1;
      }
    }
    cur += d;
  }
  cout << cur;
}