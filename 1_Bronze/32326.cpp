#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int r, g, b;
  cin >> r >> g >> b;
  cout << (r * 3 + g * 4 + b * 5);
}