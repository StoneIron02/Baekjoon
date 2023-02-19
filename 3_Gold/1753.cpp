#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E;
int k;
vector<int> dist(20001);
vector<vector<pair<int, int>>> edge(20001);

void initialize(int start) {
    for (int i = 1; i <= V; i++)
        dist[i] = INT_MAX;
    dist[start] = 0;
}

void dijkstra(int start) {
    initialize(start);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (pair<int, int>& v_pair : edge[u]) {
            int v = v_pair.first;
            int w = v_pair.second;
            if (dist[v] > dist[u] + w) {
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
    cin >> k;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }

    dijkstra(k);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}