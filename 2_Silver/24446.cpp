#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> adj[100001];
int dist[100001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> R;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= N; i++) {
    sort(adj[i].begin(), adj[i].end());
    dist[i] = -1;
  }

  queue<int> que;
  dist[R] = 0;
  que.push(R);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        que.push(v);
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << dist[i] << "\n";
  }
}