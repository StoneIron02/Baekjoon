#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int x, y, z;
  cin >> x >> y >> z;
  cout << (x + y <= z);
}