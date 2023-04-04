#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

int V, E;

bool visit[10001] {false};
vector<int> edge[10001];
vector<int> edge_rev[10001];
stack<int> stk;
int num_scc;
set<int> scc[10001];

void make_rev() {
    for (int i = 1; i <= V; i++) {
        visit[i] = false;
        vector<int>& cur_edge = edge[i];
        for (int j : cur_edge) {
            edge_rev[j].push_back(i);
        }
    }
}

void DFS(int s) {
    if (visit[s]) return;
    visit[s] = true;
    for (int v : edge[s]) {
        if (!visit[v])
            DFS(v);
    }
    stk.push(s);
}

void DFS_rev(int s) {
    if (visit[s]) return;
    visit[s] = true;
    for (int v : edge_rev[s]) {
        if (!visit[v])
            DFS_rev(v);
    }
    scc[num_scc].insert(s);
}

void KOSARAJU() {
    for (int s = 1; s <= V; s++) {
        DFS(s);
    }
    make_rev();
    num_scc = 0;
    while (!stk.empty()) {
        int s = stk.top();
        stk.pop();
        if (visit[s]) continue;
        DFS_rev(s);
        num_scc++;
    }
}

struct C {
    bool operator()(set<int>& s1, set<int>& s2) {
        return *s1.begin() < *s2.begin();
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    KOSARAJU();
    sort(scc, scc + num_scc, C());
    cout << num_scc << "\n";
    for (int i = 0; i < num_scc; i++) {
        for (auto num : scc[i])
            cout << num << " ";
        cout << "-1\n";
    }
}