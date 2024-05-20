#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  cout << min(a / 2, b);
}