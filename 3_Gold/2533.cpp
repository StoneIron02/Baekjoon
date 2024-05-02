#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[1'000'001];
bool visit[1'000'001];
int cnt = 0;

bool DFS(int s) {
  if (edges[s].empty()) {
    return false;
  }

  bool flag = false;
  for (auto v : edges[s]) {
    if (!visit[v]) {
      visit[v] = true;
      bool res = DFS(v);
      if (!res) {
        flag = true;
      }
    }
  }

  if (flag) cnt++;
  return flag;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  visit[1] = true;
  DFS(1);
  cout << cnt;
}