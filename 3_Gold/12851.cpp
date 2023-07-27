#include <iostream>
#include <queue>

using namespace std;

int n, k;
int dist[100'001];
int cases[100'001];

void BFS() {
    for (int i = 0; i <= 100'000; i++)
        dist[i] = INT32_MAX;
    dist[n] = 0;
    cases[n] = 1;
    queue<int> queue;
    queue.push(n);

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        int ds[] = {top - 1, top + 1, top * 2};
        for (auto d : ds) {
            if (d >= 0 && d <= 100'000) {
                if (dist[d] > dist[top] + 1) {
                    dist[d] = dist[top] + 1;
                    cases[d] = cases[top];
                    queue.push(d);
                } else if (dist[d] == dist[top] + 1) {
                    cases[d] += cases[top];
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
    cout << dist[k] << "\n" << cases[k];
}