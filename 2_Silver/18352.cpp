#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, k, x;
vector<int> dist(300001);
vector<vector<int>> edge(300001);

void initialize(int start) {
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[start] = 0;
}

void dijkstra(int start) {
    initialize(start);
    queue<int> queue;
    queue.push(start);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int v : edge[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                queue.push(v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }

    dijkstra(x);

    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            flag = true;
            cout << i << "\n";
        }
    }
    if (!flag) cout << "-1\n";
}