#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E;
int k;
priority_queue<int> dist[1001];
vector<pair<int, int>> edge[1001];

void initialize(int start) {
    dist[start].push(0);
}

void dijkstra(int start) {
    initialize(start);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[start].top(), start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int uCost = pq.top().first;
        pq.pop();
        for (pair<int, int>& v_pair : edge[u]) {
            int v = v_pair.first;
            int w = v_pair.second;

            // k번째까지 덜 채워졌다면 무조건 값을 받으면 됨
            if (dist[v].size() < k) {
                dist[v].push(uCost + w);
                pq.push({uCost + w, v});
            } else {
                // k번째까지 채워졌다면 루프의 종료가 필요하기 때문에 우선순위 큐가 갱신되는지 판단해야 함
                if (dist[v].top() > uCost + w) {
                    dist[v].pop();
                    dist[v].push(uCost + w);
                    pq.push({uCost + w, v});
                }
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
        edge[u].emplace_back(v, w);
    }

    dijkstra(1);

    for (int i = 1; i <= V; i++) {
        if (dist[i].size() < k)
            cout << "-1\n";
        else
            cout << dist[i].top() << "\n";
    }
}