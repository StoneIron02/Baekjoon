#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct pos {
  double x, y;
};

double dist(pos a, pos b) { return hypot(a.x - b.x, a.y - b.y); }

double ccw(pos a, pos b, pos c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  pos a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

  if (ccw(a, b, c) == 0) {
    cout << "-1.0";
    return 0;
  }

  double ab = dist(a, b);
  double bc = dist(b, c);
  double ca = dist(c, a);

  vector<double> arr;
  arr.push_back(2 * (ab + bc));
  arr.push_back(2 * (ab + ca));
  arr.push_back(2 * (bc + ca));
  
  double mx = *ranges::max_element(arr);
  double mn = *ranges::min_element(arr);
  cout << fixed << setprecision(15) << mx - mn;
}
