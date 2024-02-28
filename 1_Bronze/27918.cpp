#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int d = 0, p = 0;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'D') {
      d++;
    } else {
      p++;
    }
    if (abs(d - p) >= 2) {
      break;
    }
  }
  cout << d << ":" << p;
}