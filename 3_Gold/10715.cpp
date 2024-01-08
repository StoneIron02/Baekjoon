#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<long long, long long> p;

int n, m, c;
long long dist[100'001];
bool visit[100'001];
vector<p> edges[100'001];
long long sumDist = 0;
long long minCost = 0;

void Dijkstra(int s) {
  priority_queue<p, vector<p>, greater<>> pq;
  for (int i = 1; i <= n; i++) {
    dist[i] = INT32_MAX;
    visit[i] = false;
  }
  dist[s] = 0;
  pq.push({dist[s], s});

  while (!pq.empty()) {
    auto u = pq.top().second;
    pq.pop();

    if (visit[u])
      continue;
    visit[u] = true;

    for (auto& [v, w] : edges[u]) {
      if (visit[v]) {
        sumDist -= w;
      }
    }
    minCost = min(minCost, dist[u] * c + sumDist);

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

  cin >> n >> m >> c;
  for (int i = 0; i < m; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    edges[a].push_back({b, d});
    edges[b].push_back({a, d});
    sumDist += d;
  }
  minCost = sumDist;

  Dijkstra(1);
  cout << minCost;
}