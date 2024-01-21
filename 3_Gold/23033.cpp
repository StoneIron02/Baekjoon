#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int dist[20001];
vector<tuple<int, int, int>> edges[20001];

void Dijkstra(int s) {
  for (int i = 1; i <= n; i++) {
    dist[i] = INT32_MAX;
  }
  dist[1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({dist[1], 1});

  while (!pq.empty()) {
    auto top = pq.top();
    auto curTime = dist[top.second];
    pq.pop();

    for (auto& [v, t, w] : edges[top.second]) {
      auto startTime = curTime;
      if (curTime % w != 0) {
        startTime += w - curTime % w;
      }
      auto endTime = startTime + t;
      if (dist[v] > endTime) {
        dist[v] = endTime;
        pq.push({dist[v], v});
      }
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, t, w;
    cin >> a >> b >> t >> w;
    edges[a].push_back({b, t, w});
  }

  Dijkstra(1);
  cout << dist[n];
}