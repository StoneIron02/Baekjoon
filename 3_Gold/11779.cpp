#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> edge[1001];
int dist[1001];
int predecessor[1001];
int s, d;

void Backtracking(int cur, int len) {
    if (cur == -1) {
        cout << len << "\n";
        return;
    }
    Backtracking(predecessor[cur], len + 1);
    cout << cur << " ";
}

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        dist[i] = INT32_MAX;
        predecessor[i] = -1;
    }
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        auto u = top.second;

        if (u == d)
            break;

        for (auto e : edge[u]) {
            auto v = e.first;
            auto w = e.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                predecessor[v] = u;
                pq.push({dist[v], v});
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
    cin >> s >> d;
    Dijkstra();
    cout << dist[d] << "\n";
    Backtracking(d, 0);
}