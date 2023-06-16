#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 2000000000
int TC;
int N, M, W;
int dist[501];
vector<tuple<int, int, int>> edge;

bool BellmanFord(int s) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;

    for (int i = 1 ; i < N ;i++) {
        for (auto e : edge) {
            auto u = get<0>(e);
            auto v = get<1>(e);
            auto w = get<2>(e);
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto e : edge) {
        auto u = get<0>(e);
        auto v = get<1>(e);
        auto w = get<2>(e);
        if (dist[v] > dist[u] + w) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        edge.clear();

        for (int i = 0; i < M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edge.emplace_back(s, e, t);
            edge.emplace_back(e, s, t);
        }
        for (int i = 0; i < W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edge.emplace_back(s, e, -t);
        }

        if (BellmanFord(1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}