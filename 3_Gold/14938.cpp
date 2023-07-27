#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;
int items[101];
vector<pair<int, int>> edge[101];
int dist[101];

void Dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = INT32_MAX;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.second;

        for (auto e : edge[u]) {
            auto v = e.first;
            auto w = e.second;
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

    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> items[i];
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        edge[a].emplace_back(b, l);
        edge[b].emplace_back(a, l);
    }

    int maxTotal = 0;
    for (int i = 1; i <= n; i++) {
        Dijkstra(i);
        int total = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[j] <= m) {
                total += items[j];
            }
        }
        maxTotal = max(maxTotal, total);
    }
    cout << maxTotal;
}