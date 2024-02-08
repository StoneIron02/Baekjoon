#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define SHIFT 10000

int n, m;
bool visit[20001];
vector<int> edges[20001];
vector<int> edges_rev[20001];
stack<int> st;
int scc[20001];
int label = 0;

void make_rev() {
  for (int i = 0; i <= 20000; i++) {
    for (auto j : edges[i]) {
      edges_rev[j].push_back(i);
    }
  }
}

void DFS(int s) {
  for (auto v : edges[s]) {
    if (!visit[v]) {
      visit[v] = true;
      DFS(v);
      st.push(v);
    }
  }
}

void DFS_rev(int s) {
  for (auto v : edges_rev[s]) {
    if (!visit[v]) {
      visit[v] = true;
      scc[v] = label;
      DFS_rev(v);
    }
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    int not_a = -a;
    int not_b = -b;

    edges[SHIFT + not_a].push_back(SHIFT + b);
    edges[SHIFT + not_b].push_back(SHIFT + a);
  }

  make_rev();

  for (int i = SHIFT + 1; i <= SHIFT + n; i++) {
    if (!visit[i]) {
      visit[i] = true;
      DFS(i);
      st.push(i);
    }
  }
  for (int i = SHIFT - 1; i >= SHIFT - n; i--) {
    if (!visit[i]) {
      visit[i] = true;
      DFS(i);
      st.push(i);
    }
  }

  for (int v = 0; v <= 20000; v++) {
    visit[v] = false;
  }

  while (!st.empty()) {
    auto v = st.top();
    st.pop();
    if (!visit[v]) {
      visit[v] = true;
      scc[v] = label;
      DFS_rev(v);
      label++;
    }
  }

  for (int i = 1; i <= n; i++) {
    int not_i = -i;
    if (scc[SHIFT + i] == scc[SHIFT + not_i]) {
      cout << 0;
      exit(0);
    }
  }
  cout << 1;
}