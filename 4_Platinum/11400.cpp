#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[100001];

bool visit[100001];
int entryTime[100001], minEntryTime[100001];
vector<pair<int, int>> bridges;
int timer = 0;

void DFS(int cur, int before = -1) {
  visit[cur] = true;
  entryTime[cur] = minEntryTime[cur] = timer++;

  for (int to : adj[cur]) {
    if (to == before) continue;
    if (visit[to]) {
      minEntryTime[cur] = min(minEntryTime[cur], entryTime[to]);
    } else {
      DFS(to, cur);
      minEntryTime[cur] = min(minEntryTime[cur], minEntryTime[to]);
      if (minEntryTime[to] > entryTime[cur])
        bridges.emplace_back(min(cur, to), max(cur, to));
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }

  for (int i = 1; i <= n; ++i) {
    if (!visit[i])
      DFS(i);
  }

  sort(bridges.begin(), bridges.end());
  cout << bridges.size() << "\n";
  for (auto& [a, b] : bridges) {
    cout << a << " " << b << "\n";
  }
}