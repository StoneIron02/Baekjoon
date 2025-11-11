#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int first = (x2 - x1) * (y2 - y1);
    int overlapX = max(0, min(x2, x4) - max(x1, x3));
    int overlapY = max(0, min(y2, y4) - max(y1, y3));
    int overlap = overlapX * overlapY;
    cout << first - overlap << '\n';
  }
}
