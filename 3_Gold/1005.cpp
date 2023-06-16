#include <iostream>
#include <vector>

using namespace std;

int N, K;
int t[1001];
bool visit[1001];
int dist[1001];
vector<int> edge[1001];

int DFS(int cur) {
    if (edge[cur].empty()) {
        dist[cur] = t[cur];
        return t[cur];
    }

    int maxSum = 0;
    for (auto v : edge[cur]) {
        if (!visit[v]) {
            visit[v] = true;
            int sum = DFS(v);
            maxSum = max(maxSum, sum);
        } else {
            int sum = dist[v];
            maxSum = max(maxSum, sum);
        }
    }
    int result = maxSum + t[cur];
    dist[cur] = result;
    return result;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            edge[i].clear();
            visit[i] = false;
            dist[i] = 0;
            cin >> t[i];
        }
        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            edge[b].push_back(a);
        }
        int w;
        cin >> w;
        visit[w] = true;
        cout << DFS(w) << "\n";
    }

}