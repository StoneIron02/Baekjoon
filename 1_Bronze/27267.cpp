#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int S1 = a * b;
  int S2 = c * d;
  if (S1 > S2) {
    cout << "M";
  } else if (S1 < S2) {
    cout << "P";
  } else {
    cout << "E";
  }
}