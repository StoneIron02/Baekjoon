#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c;
  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;

    if (b - a == c - b) {
      int d = b - a;
      cout << "AP " << c + d << "\n";
    } else {
      int r = b / a;
      cout << "GP " << c * r << "\n";
    }
  }
}