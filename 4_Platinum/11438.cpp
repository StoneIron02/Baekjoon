#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> edges[100'001];
int parent[100'001][20];
int depth[100'001];
bool visit[100'001];
int maxDepth;

void DFS(int cur) {
  for (auto i : edges[cur]) {
    if (!visit[i]) {
      visit[i] = true;
      parent[i][0] = cur;
      for (int j = 1; j <= maxDepth; j++) {
        parent[i][j] = parent[parent[i][j - 1]][j - 1];
      }
      depth[i] = depth[cur] + 1;
      DFS(i);
    }
  }
}

void LCA(int a, int b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }

  for (int i = maxDepth; i >= 0; i--) {
    if (depth[a] - depth[b] >= (1 << i)) {
      a = parent[a][i];
    }
  }

  if (a != b) {
    for (int i = maxDepth; i >= 0; i--) {
      if (parent[a][i] != parent[b][i]) {
        a = parent[a][i];
        b = parent[b][i];
      }
    }
    a = parent[a][0];
    b = parent[b][0];
  }

  cout << a << "\n";
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  maxDepth = (int)floor(log2(100001));

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  visit[1] = true;
  depth[1] = 0;
  DFS(1);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    LCA(a, b);
  }
}