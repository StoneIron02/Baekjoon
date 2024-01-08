#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, d, c;
int dist[10001];
vector<pii> edges[10001];

void Dijkstra() {
  for (int i = 1; i <= n; i++) {
    dist[i] = INT32_MAX;
  }
  priority_queue<pii, vector<pii>, greater<>> pq;
  dist[c] = 0;
  pq.push({dist[c], c});

  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    auto u = top.second;

    for (auto& [v, w] : edges[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> d >> c;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
    }
    for (int i = 0; i < d; i++) {
      int a, b, s;
      cin >> a >> b >> s;
      edges[b].push_back({a, s});
    }
    Dijkstra();
    int cnt = 0;
    int maxVal = 0;
    for (int i = 1; i <= n; i++) {
      if (dist[i] != INT32_MAX) {
        cnt++;
        maxVal = max(maxVal, dist[i]);
      }
    }

    cout << cnt << " " << maxVal << "\n";
  }
}