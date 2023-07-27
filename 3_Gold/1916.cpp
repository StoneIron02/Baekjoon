#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dist[1001];
vector<pair<int, int>> edge[1001];

void Dijkstra(int s, int d) {
    for (int i = 1; i <= 1000; i++)
        dist[i] = INT32_MAX;
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        auto u = top.second;

        if (top.second == d)
            break;

        for (auto v : edge[u]) {
            int w = v.second;
            if (dist[v.first] > dist[u] + w) {
                dist[v.first] = dist[u] + w;
                pq.push({dist[u] + w, v.first});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a].emplace_back(b, w);
    }
    int s, d;
    cin >> s >> d;
    Dijkstra(s, d);
    cout << dist[d];
}