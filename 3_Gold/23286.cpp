#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
int N, M, T;
int dist[301];
vector<pii> adj[301];

void Dijkstra(int s, int e) {
  for (int i = 0; i <= N; i++) {
    dist[i] = INT_MAX;
  }
  priority_queue<pii, vector<pii>, greater<>> pq;
  dist[s] = 0;
  pq.emplace(dist[s], s);

  while (!pq.empty()) {
    auto [u_dist, u] = pq.top();
    pq.pop();

    if (u == e) {
      break;
    }

    for (auto& [v, w] : adj[u]) {
      if (dist[v] > max(dist[u], w)) {
        dist[v] = max(dist[u], w);
        pq.emplace(dist[v], v);
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> N >> M >> T;
  for (int i = 0; i < M; i++) {
    int u, v, h;
    cin >> u >> v >> h;
    adj[u].emplace_back(v, h);
  }
  for (int i = 0; i < T; i++) {
    int s, e;
    cin >> s >> e;
    Dijkstra(s, e);
    cout << (dist[e] == INT_MAX ? -1 : dist[e]) << "\n";
  }
}
