#include <iostream>
#include <queue>

using namespace std;

int n, k;
int dist[100'001];

void BFS() {
    queue<int> queue;
    for (int i = 0; i <= 100'000; i++) {
        dist[i] = INT32_MAX;
    }
    dist[n] = 0;
    queue.push(n);

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        if (top == k)
            break;

        int dx[3] = {top + 1, top - 1, top * 2};
        for (int curDx : dx) {
            if (curDx < 0 || curDx > 100'000) continue; // out of index
            if (curDx == top * 2) {
                if (dist[curDx] > dist[top]) {
                    dist[curDx] = dist[top];
                    queue.push(curDx);
                }
            } else {
                if (dist[curDx] > dist[top] + 1) {
                    dist[curDx] = dist[top] + 1;
                    queue.push(curDx);
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    BFS();
    cout << dist[k];
}