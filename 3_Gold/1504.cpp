#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
long long dist[801];
vector<pair<int, int>> edges[801];

void Dijkstra(int s) {
    for (int i = 1; i <= V; i++) {
        dist[i] = INT64_MAX;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        pair<long long, int> u_pq = pq.top();
        int u = u_pq.second;
        pq.pop();

        for (pair<int, int> v_edge : edges[u]) {
            int v = v_edge.first;
            int w = v_edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
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
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }
    int v1, v2;
    cin >> v1 >> v2;

    Dijkstra(v1);
    long long dijk_1_v1 = dist[1];
    long long dijk_v1_v = dist[V];
    long long dist_require = dist[v2];
    Dijkstra(v2);
    long long dijk_1_v2 = dist[1];
    long long dijk_v2_v = dist[V];

    long long dist1 = dijk_1_v1 + dist_require + dijk_v2_v;
    long long dist2 = dijk_1_v2 + dist_require + dijk_v1_v;
    if (dijk_1_v1 == INT64_MAX || dijk_v2_v == INT64_MAX || dist_require == INT64_MAX)
        dist1 = -1;
    if (dijk_1_v2 == INT64_MAX || dijk_v1_v == INT64_MAX || dist_require == INT64_MAX)
        dist2 = -1;

    if (dist1 < 0) {
        cout << dist2;
    } else {
        if (dist2 < 0) {
            cout << dist1;
        } else {
            cout << min(dist1, dist2);
        }
    }
}