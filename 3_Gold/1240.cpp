#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> edges[1001];
int dist[1001];

void BFS(int s, int d) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT32_MAX;
    }
    queue<int> queue;
    dist[s] = 0;
    queue.push(s);

    while (!queue.empty()) {
        auto u = queue.front();
        queue.pop();

        if (u == d)
            break;

        for (auto v_pair : edges[u]) {
            auto v = v_pair.first;
            auto w = v_pair.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                queue.push(v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].emplace_back(b, w);
        edges[b].emplace_back(a, w);
    }

    while (m--) {
        int s, d;
        cin >> s >> d;
        BFS(s, d);
        cout << dist[d] << "\n";
    }
}