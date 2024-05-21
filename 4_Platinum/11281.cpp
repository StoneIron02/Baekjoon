#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define SHIFT 10000

int n, m;
bool visit[2 * SHIFT + 1];
vector<int> edges[2 * SHIFT + 1];
vector<int> edges_rev[2 * SHIFT + 1];
stack<int> st;
int scc[2 * SHIFT + 1];
int label = 0;

void make_rev() {
  for (int i = 0; i <= 2 * SHIFT; i++) {
    for (auto j : edges[i]) {
      edges_rev[j].push_back(i);
    }
  }
}

void DFS(int s) {
  visit[s] = true;
  for (auto v : edges[s]) {
    if (!visit[v]) {
      DFS(v);
    }
  }
  st.push(s);
}

void DFS_rev(int s) {
  visit[s] = true;
  scc[s] = label;
  for (auto v : edges_rev[s]) {
    if (!visit[v]) {
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
      DFS(i);
    }
  }
  for (int i = SHIFT - 1; i >= SHIFT - n; i--) {
    if (!visit[i]) {
      DFS(i);
    }
  }

  for (int v = 0; v <= 20000; v++) {
    visit[v] = false;
  }

  while (!st.empty()) {
    int v = st.top();
    st.pop();
    if (!visit[v]) {
      label++;
      DFS_rev(v);
    }
  }

  for (int i = 1; i <= n; i++) {
    int not_i = -i;
    if (scc[SHIFT + i] == scc[SHIFT + not_i]) {
      cout << 0;
      exit(0);
    }
  }
  cout << 1 << "\n";

  for (int i = 1; i <= n; i++) {
    int not_i = -i;
    cout << (scc[SHIFT + i] > scc[SHIFT + not_i]) << " ";
  }
}