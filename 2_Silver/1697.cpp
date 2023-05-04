#include <iostream>
#include <queue>

using namespace std;

int dist[100'001];

void BFS(int n, int k) {
    for (auto& i : dist) {
        i = INT32_MAX;
    }
    queue<int> queue;
    queue.push(n);
    dist[n] = 0;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        if (u == k)
            return;

        if (dist[u - 1] > dist[u] + 1) {
            dist[u - 1] = dist[u] + 1;
            queue.push(u - 1);
        }
        if (u + 1 <= 100'000 && dist[u + 1] > dist[u] + 1) {
            dist[u + 1] = dist[u] + 1;
            queue.push(u + 1);
        }
        if (u * 2 <= 100'000 && dist[u * 2] > dist[u] + 1) {
            dist[u * 2] = dist[u] + 1;
            queue.push(u * 2);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int k;
    cin >> k;

    BFS(n, k);
    cout << dist[k];
}