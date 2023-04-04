#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>

using namespace std;

int V, E;
tuple<int, int, int, int> pos[100'000];
bool visit[100'000];
int dist[100'000];
vector<pair<int, int>> edges[100'000];

struct compareX {
    bool operator()(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
        return get<0>(a) < get<0>(b);
    }
};

struct compareY {
    bool operator()(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
        return get<1>(a) < get<1>(b);
    }
};

struct compareZ {
    bool operator()(tuple<int, int, int, int>& a, tuple<int, int, int, int>& b) {
        return get<2>(a) < get<2>(b);
    }
};

int get_min(int i, int j) {
    int diffX = abs(get<0>(pos[i]) - get<0>(pos[j]));
    int diffY = abs(get<1>(pos[i]) - get<1>(pos[j]));
    int diffZ = abs(get<2>(pos[i]) - get<2>(pos[j]));
    return min({diffX, diffY, diffZ});
}

int mst_prim(int start) {
    int mst = 0;
    int visitNum = 0;
    for (int & i : dist)
        i = INT_MAX;
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        if (visitNum > V - 1) break;

        int u = pq.top().second;
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;
        visitNum++;
        mst += dist[u];

        for (pair<int, int>& v : edges[u]) {
            int adjacent = v.first;
            int w = v.second;
            if (!visit[adjacent]) {
                dist[adjacent] = min(dist[adjacent], w);
                pq.push({dist[adjacent], adjacent});
            }
        }
    }
    return mst;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V;
    for (int i = 0; i < V; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pos[i] = {x, y, z, i};
    }

    sort(pos, pos + V, compareX());
    for (int i = 0; i < V - 1; i++) {
        int min = get_min(i, i + 1);
        edges[get<3>(pos[i])].emplace_back(get<3>(pos[i + 1]), min);
        edges[get<3>(pos[i + 1])].emplace_back(get<3>(pos[i]), min);
    }

    sort(pos, pos + V, compareY());
    for (int i = 0; i < V - 1; i++) {
        int min = get_min(i, i + 1);
        edges[get<3>(pos[i])].emplace_back(get<3>(pos[i + 1]), min);
        edges[get<3>(pos[i + 1])].emplace_back(get<3>(pos[i]), min);
    }

    sort(pos, pos + V, compareZ());
    for (int i = 0; i < V - 1; i++) {
        int min = get_min(i, i + 1);
        edges[get<3>(pos[i])].emplace_back(get<3>(pos[i + 1]), min);
        edges[get<3>(pos[i + 1])].emplace_back(get<3>(pos[i]), min);
    }

    cout << mst_prim(0);
}