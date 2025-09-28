#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> adj[100'001];
int dist[100'001];
int order[100'001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> R;

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= N; ++i) {
    sort(adj[i].begin(), adj[i].end());
    dist[i] = -1;
  }

  queue<int> que;
  int visit_cnt = 1;
  dist[R] = 0;
  order[R] = visit_cnt++;
  que.push(R);

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        order[v] = visit_cnt++;
        que.push(v);
      }
    }
  }

  long long res = 0;
  for (int i = 1; i <= N; ++i) {
    if (order[i] == 0) continue;
    res += 1LL * dist[i] * order[i];
  }
  cout << res;
}