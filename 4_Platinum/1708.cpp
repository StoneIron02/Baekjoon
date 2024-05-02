#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef pair<int, int> point;

vector<point> points;

bool compare(const point& p1, const point& p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}

long long ccw(const point& p1, const point& p2, const point& p3) {
  return ((1LL * p2.first - p1.first) * (1LL * p3.second - p1.second) - (1LL * p2.second - p1.second) * (1LL * p3.first - p1.first));
}

double distance(const point& p1, const point& p2) {
  return sqrt((1LL * p2.first - p1.first) * (1LL * p2.first - p1.first)
              + (1LL * p2.second - p1.second) * (1LL * p2.second - p1.second));
}

bool compare_ccw(const point& p1, const point& p2) {
  long long c = ccw(points[0], p2, p1);
  if (c == 0) {
    return distance(points[0], p1) < distance(points[0], p2);
  }
  return c > 0;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int minIndex = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
    if (compare(points[i], points[minIndex])) {
      minIndex = i;
    }
  }
  swap(points[0], points[minIndex]);
  sort(points.begin() + 1, points.end(), compare_ccw);

  stack<point> stk;
  stk.push(points[0]);
  stk.push(points[1]);
  for (int i = 2; i < n; i++) {
    while (stk.size() >= 2) {
      point p2 = stk.top();
      stk.pop();
      point p1 = stk.top();
      if (ccw(p1, p2, points[i]) < 0) {
        stk.push(p2);
        break;
      }
    }
    stk.push(points[i]);
  }

  cout << stk.size();
}