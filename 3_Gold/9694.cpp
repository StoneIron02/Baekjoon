#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, m;
int dist[20];
int back[20];
vector<pii> edges[20];

void Dijkstra() {
    for (int i = 0; i < m; i++) {
        dist[i] = INT32_MAX;
        back[i] = -1;
    }
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[0] = 0;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        auto pos = top.second;

        for (auto& [v, w] : edges[pos]) {
            if (dist[v] > dist[pos] + w) {
                dist[v] = dist[pos] + w;
                back[v] = pos;
                pq.push({dist[v], v});
            }
        }
    }
}

void Backtracking(int p) {
    if (p == -1) return;
    Backtracking(back[p]);
    cout << p << " ";
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            edges[i].clear();
        }
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges[x].push_back({y, z});
            edges[y].push_back({x, z});
        }
        Dijkstra();
        if (dist[m - 1] == INT32_MAX) {
            cout << "Case #" << c << ": " << -1 << "\n";
        } else {
            cout << "Case #" << c << ": ";
            Backtracking(m - 1);
            cout << "\n";
        }
    }
}