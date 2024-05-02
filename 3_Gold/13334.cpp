#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

bool comp(pii& a, pii& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pii> vec(n);
  for (int i = 0; i < n; i++) {
    int h, o;
    cin >> h >> o;
    if (h > o) {
      int tmp = h;
      h = o;
      o = tmp;
    }
    vec[i] = {h, o};
  }
  int d;
  cin >> d;

  sort(vec.begin(), vec.end(), comp);

  int maxCnt = 0;
  priority_queue<int, vector<int>, greater<>> pq;
  for (auto& [start, end] : vec) {
    pq.push(start);
    int l = end - d;
    while (!pq.empty() && pq.top() < l) {
      pq.pop();
    }
    maxCnt = max(maxCnt, (int)pq.size());
  }
  cout << maxCnt;
}