#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int m, k;
  cin >> m >> k;
  cout << (m % k == 0 ? "Yes" : "No");
}