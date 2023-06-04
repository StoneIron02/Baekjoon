#include <iostream>
#include <queue>

using namespace std;

int n, m;
int toGo[101];
int dist[101];

void BFS(int s) {
    for (int i = 1; i <= 100; i++) {
        dist[i] = INT32_MAX;
    }
    queue<int> queue;
    dist[s] = 0;
    queue.push(s);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        if (u == 100)
            break;

        for (int i = 1; i <= 6; i++) {
            int d = u + i;
            if (toGo[d] != -1) {
                d = toGo[d];
            }
            if (d > 100)
                continue;
            if (dist[d] > dist[u] + 1) {
                dist[d] = dist[u] + 1;
                queue.push(d);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= 100; i++) {
        toGo[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        toGo[a] = b;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        toGo[a] = b;
    }

    BFS(1);
    cout << dist[100];
}