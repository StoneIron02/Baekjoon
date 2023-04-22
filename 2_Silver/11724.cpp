#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
bool visit[1001] {false};
vector<int> edge[1001];
int num_component = 0;

void BFS(int s) {
    visit[s] = true;
    num_component++;
    queue<int> queue;
    queue.push(s);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int v : edge[u]) {
            if (!visit[v]) {
                visit[v] = true;
                queue.push(v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int s = 1; s <= V; s++) {
        if (!visit[s])
            BFS(s);
    }

    cout << num_component;
}