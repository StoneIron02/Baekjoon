#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

double dist(pii& p1, pii& p2) {
  return sqrt((p2.second - p1.second) * (p2.second - p1.second) + (p2.first - p1.first) * (p2.first - p1.first));
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  pii p[4];
  for (int i = 0; i < 4; i++) {
    int a, b;
    cin >> a >> b;
    p[i] = {a, b};
  }
  double res = min({
    dist(p[0], p[1]) + dist(p[1], p[2]) + dist(p[2], p[3]),
    dist(p[0], p[1]) + dist(p[1], p[3]) + dist(p[3], p[2]),
    dist(p[0], p[2]) + dist(p[2], p[1]) + dist(p[1], p[3]),
    dist(p[0], p[2]) + dist(p[2], p[3]) + dist(p[3], p[1]),
    dist(p[0], p[3]) + dist(p[3], p[1]) + dist(p[1], p[2]),
    dist(p[0], p[3]) + dist(p[3], p[2]) + dist(p[2], p[1])
  });
  cout << ((int)res);
}
