#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define NONE 0
#define A 1
#define B 2

using namespace std;

int V, E;
int J, K;
vector<int> dist(5001);
vector<vector<pair<int, int>>> edge(5001);
vector<int> type(5001);

void initialize(int start) {
    for (int i = 0; i <= V; i++)
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
    cin >> J >> K;
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        type[num] = A;
    }
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        type[num] = B;
    }
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    dijkstra(J);

    int minA = 0, minB = 0;
    for (int i = 1; i <= V; i++) {
        if (i == J) continue;
        if (type[i] == A)
            minA = (dist[i] < dist[minA] ? i : minA);
        else if (type[i] == B)
            minB = (dist[i] < dist[minB] ? i : minB);
    }

    if (dist[minA] == INT_MAX && dist[minB] == INT_MAX) {
        cout << "-1";
        exit(0);
    }

    if (dist[minA] <= dist[minB])
        cout << "A\n" << dist[minA];
    else
        cout << "B\n" << dist[minB];
}