#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, m;
bool visit[100001];
vector<pii> edges[100001];

int mst_prim(int start) {
  int cnt = 0;
  priority_queue<pii, vector<pii>, greater<>> pq;
  pq.emplace(0, start);

  int sum = 0;
  int maxDist = 0;

  while (!pq.empty()) {
    if (cnt >= n) break;

    auto [d, u] = pq.top();
    pq.pop();

    if (visit[u]) continue;
    visit[u] = true;
    cnt++;
    sum += d;
    maxDist = max(maxDist, d);

    for (auto& [v, w] : edges[u]) {
      if (!visit[v]) {
        pq.emplace(w, v);
      }
    }
  }
  return sum - maxDist;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }

  cout << mst_prim(1);
}