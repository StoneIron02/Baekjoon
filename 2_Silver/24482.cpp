#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> adj[100'001];
int dist[100'001];
bool visit[100'001];

void dfs(int node, int d) {
  visit[node] = true;
  dist[node] = d;
  for (int next : adj[node]) {
    if (!visit[next]) {
      dfs(next, d + 1);
    }
  }
}

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
    sort(adj[i].rbegin(), adj[i].rend());
    dist[i] = -1;
  }

  dfs(R, 0);
  for (int i = 1; i <= N; i++) {
    cout << dist[i] << "\n";
  }
}