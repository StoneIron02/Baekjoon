#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m;
bool visit[32001] {false};
vector<int> edges[32001];
stack<int> topological;

void dfs(int s) {
    visit[s] = true;
    for (int v : edges[s]) {
        if (!visit[v])
            dfs(v);
    }
    topological.push(s);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if (!visit[i])
            dfs(i);

    while (!topological.empty()) {
        cout << topological.top() << " ";
        topological.pop();
    }
}