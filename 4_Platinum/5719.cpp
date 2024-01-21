#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int s, d;
int dist[500];
vector<pii> edges[500];
vector<int> back[500];
bool visit[500];

void Dijkstra() {
  priority_queue<pii, vector<pii>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    dist[i] = INT32_MAX;
  }
  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    auto pos = top.second;

    for (auto& [v, w] : edges[pos]) {
      if (w == -1) continue;
      if (dist[v] > dist[pos] + w) {
        dist[v] = dist[pos] + w;
        back[v].clear();
        back[v].push_back(pos);
        pq.push({dist[v], v});
      }
      else if (dist[v] == dist[pos] + w) {
        back[v].push_back(pos);
      }
    }
  }
}

void BFS(int pos) {
  queue<int> que;
  que.push(pos);

  while (!que.empty()) {
    auto top = que.front();
    que.pop();

    if (visit[top]) continue;
    visit[top] = true;

    for (auto& v : back[top]) {
      que.push(v);
      // find edge
      for (auto& [vOrigin, wOrigin] : edges[v]) {
        if (vOrigin == top) {
          wOrigin = -1;
        }
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    for (int i = 0; i < n; i++) {
      edges[i].clear();
      back[i].clear();
      visit[i] = false;
    }
    cin >> s >> d;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[u].push_back({v, w});
    }
    Dijkstra();
    BFS(d);

    Dijkstra();
    if (dist[d] == INT32_MAX) {
      cout << -1 << "\n";
      continue;
    }
    cout << dist[d] << "\n";
  }
}