#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;
  int dist1 = b - a - 1;
  int dist2 = c - b - 1;
  cout << max(dist1, dist2);
}