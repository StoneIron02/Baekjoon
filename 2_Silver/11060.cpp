#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int arr[1001];
    int dist[1001];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dist[i] = INT32_MAX;
    }
    queue<int> queue;
    dist[1] = 0;
    queue.push(1);
    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (int i = 0; i <= arr[top]; i++) {
            int dx = top + i;
            if (dx > n) continue;
            if (dist[dx] > dist[top] + 1) {
                dist[dx] = dist[top] + 1;
                queue.push(dx);
            }
        }
    }
    cout << (dist[n] == INT32_MAX ? -1 : dist[n]);
}