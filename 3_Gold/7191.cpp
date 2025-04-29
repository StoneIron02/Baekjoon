#include <iostream>
#include <deque>
#include <vector>
using namespace std;

bool visit[10001];
int parent[10001];
vector<int> children[10001];
vector<int> res[10001];

int N, K;

void DFS(int before, int cur) {
  visit[cur] = true;

  int idx;
  for (idx = 0; idx < children[cur].size(); idx++) {
    if (children[cur][idx] == before) break;
  }

  for (int i = idx + 1; i < children[cur].size(); i++) {
    int next = children[cur][i];
    if (!visit[next]) {
      res[cur].push_back(next);
      DFS(cur, next);
    }
  }

  if (parent[cur] != 0) {
    int next = parent[cur];
    if (!visit[next]) {
      res[cur].push_back(next);
      DFS(cur, next);
    }
  }

  for (int i = 0; i < idx; i++) {
    int next = children[cur][i];
    if (!visit[next]) {
      res[cur].push_back(next);
      DFS(cur, next);
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    int m;
    cin >> m;
    for (int j = 1; j <= m; j++) {
      int num;
      cin >> num;
      children[i].push_back(num);
      parent[num] = i;
    }
  }

  if (N == 1) {
    cout << 0;
    return 0;
  }

  visit[K] = true;
  res[K].push_back(parent[K]);
  DFS(K, parent[K]);
  for (int i = 1; i <= N; i++) {
    cout << res[i].size() << " ";
    for (auto i : res[i]) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
