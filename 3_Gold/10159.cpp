#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool visit[101];
vector<int> edges1[101];
vector<int> edges2[101];

int BFS1(int s) {
  for (int i = 1; i <= n; i++) {
    visit[i] = false;
  }
  visit[s] = true;
  queue<int> q;
  q.push(s);

  int cnt = 0;
  while (!q.empty()) {
    auto top = q.front();
    q.pop();

    for (auto v : edges1[top]) {
      if (!visit[v]) {
        visit[v] = true;
        q.push(v);
        cnt++;
      }
    }
  }
  return cnt;
}

int BFS2(int s) {
  for (int i = 1; i <= n; i++) {
    visit[i] = false;
  }
  visit[s] = true;
  queue<int> q;
  q.push(s);

  int cnt = 0;
  while (!q.empty()) {
    auto top = q.front();
    q.pop();

    for (auto v : edges2[top]) {
      if (!visit[v]) {
        visit[v] = true;
        q.push(v);
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges1[a].push_back(b);
    edges2[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    int cnt1 = BFS1(i);
    int cnt2 = BFS2(i);
    cout << (n - cnt1 - cnt2 - 1) << "\n";
  }
}