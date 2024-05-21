#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edges[50'001];
int parent[50'001];
int depth[50'001];
bool visit[50'001];

void DFS(int cur) {
  for (auto i : edges[cur]) {
    if (!visit[i]) {
      visit[i] = true;
      parent[i] = cur;
      depth[i] = depth[cur] + 1;
      DFS(i);
    }
  }
}

void LCA(int a, int b) {
  if (depth[a] < depth[b]) {
    swap(a, b);
  }
  while (depth[a] > depth[b]) {
    a = parent[a];
  }

  while (a != b) {
    a = parent[a];
    b = parent[b];
  }

  cout << a << "\n";
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

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