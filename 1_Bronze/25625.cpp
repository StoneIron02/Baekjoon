#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int x, y;
  cin >> x >> y;
  if (x < y) {
    cout << y - x;
  } else {
    cout << x + y;
  }
}