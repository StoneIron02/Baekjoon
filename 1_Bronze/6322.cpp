#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int i = 1;
  double a, b, c;
  while (true) {
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) break;

    cout << "Triangle #" << i++ << "\n";
    if (c == -1) {
      c = sqrt(a * a + b * b);
      if (a + b > c) {
        cout << fixed << setprecision(3) << "c = " << c << "\n";
      } else {
        cout << "Impossible.\n";
      }
    } else if (a == -1) {
      a = sqrt(c * c - b * b);
      if (a + b > c) {
        cout << fixed << setprecision(3) << "a = " << a << "\n";
      } else {
        cout << "Impossible.\n";
      }
    } else {
      b = sqrt(c * c - a * a);
      if (a + b > c) {
        cout << fixed << setprecision(3) << "b = " << b << "\n";
      } else {
        cout << "Impossible.\n";
      }
    }
    cout << "\n";
  }
}