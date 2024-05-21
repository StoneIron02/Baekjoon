#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[10001];

bool visit[10001];
int entryTime[10001], minEntryTime[10001];
bool isCutPoint[10001];
int timer = 0;

void DFS(int cur, int before = -1) {
  visit[cur] = true;
  entryTime[cur] = minEntryTime[cur] = timer++;
  int children = 0;

  for (int to : adj[cur]) {
    if (to == before) continue;
    if (visit[to]) {
      minEntryTime[cur] = min(minEntryTime[cur], entryTime[to]);
    } else {
      DFS(to, cur);
      minEntryTime[cur] = min(minEntryTime[cur], minEntryTime[to]);
      if (minEntryTime[to] >= entryTime[cur] && before != -1)
        isCutPoint[cur] = true;
      ++children;
    }
  }

  if(before == -1 && children > 1)
    isCutPoint[cur] = true;
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

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (isCutPoint[i]) {
      ++cnt;
    }
  }
  cout << cnt << "\n";

  for (int i = 1; i <= n; i++) {
    if (isCutPoint[i]) {
      cout << i << " ";
    }
  }
}