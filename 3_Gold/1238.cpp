#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, X;
int dist[1001];
vector<pair<int, int>> edge[1001];
vector<pair<int, int>> edge_rev[1001];

void Dijkstra(int s, vector<pair<int, int>>* edges) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INT32_MAX;
    }
    priority_queue<pair<int, int>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto top = pq.top();
        auto u = top.second;
        pq.pop();

        for (auto v_pair : edges[u]) {
            auto v = v_pair.first;
            auto uv = v_pair.second;
            if (dist[v] > dist[u] + uv) {
                dist[v] = dist[u] + uv;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edge[s].emplace_back(d, w);
        edge_rev[d].emplace_back(s, w);
    }

    int dist1[1001];
    Dijkstra(X, edge);
    for (int i = 1; i <= N; i++) {
        dist1[i] = dist[i];
    }

    int dist2[1001];
    Dijkstra(X, edge_rev);
    for (int i = 1; i <= N; i++) {
        dist2[i] = dist[i];
    }

    int maxSum = -1;
    for (int i = 1; i <= N; i++) {
        int sum = dist1[i] + dist2[i];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
}