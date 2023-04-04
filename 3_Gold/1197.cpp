#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E;
bool visit[10001];
int dist[10001];
vector<pair<int, int>> edges[10001];

int mst_prim(int start) {
    int mst = 0;
    int visitNum = 0;
    for (int i = 1; i <= 10000; i++)
        dist[i] = INT_MAX;
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        if (visitNum > V - 1) break;

        int u = pq.top().second;
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;
        visitNum++;
        mst += dist[u];

        for (pair<int, int>& v : edges[u]) {
            int adjacent = v.first;
            int w = v.second;
            if (!visit[adjacent]) {
                dist[adjacent] = min(dist[adjacent], w);
                pq.push({dist[adjacent], adjacent});
            }
        }
    }
    return mst;
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

    cout << mst_prim(1);
}