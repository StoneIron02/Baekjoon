#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int V;
vector<int> edges[51];
int dist[51];

void BFS(int s) {
    for (int i = 1; i <= V; i++) {
        dist[i] = INT32_MAX;
    }
    queue<int> queue;
    dist[s] = 0;
    queue.push(s);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (int v : edges[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                queue.push(v);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V;
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int presidentPoint = INT32_MAX;
    set<int> president;
    for (int i = 1; i <= V; i++) {
        BFS(i);
        int M = 0;
        for (int j = 1; j <= V; j++) {
            if (i == j) continue;
            if (M < dist[j])
                M = dist[j];
        }
        if (presidentPoint > M) {
            presidentPoint = M;
            president.clear();
        }
        if (presidentPoint == M) {
            president.insert(i);
        }
    }
    cout << presidentPoint << " " << president.size() << "\n";
    for (auto p : president) {
        cout << p << " ";
    }
}