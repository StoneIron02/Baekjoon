#include <iostream>
#include <vector>

using namespace std;

int V;
vector<pair<int, int>> adjacent[100'001];
bool visit[100'001];
int maxDist = -1;
int maxDistNum = -1;

void DFS(int u, int sum) {
    for (auto v : adjacent[u]) {
        auto num = v.first;
        auto w = v.second;
        if (!visit[num]) {
            visit[num] = true;
            DFS(num, sum + w);
        }
    }
    if (maxDist < sum) {
        maxDist = sum;
        maxDistNum = u;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V;
    for (int i = 1; i <= V; i++) {
        int src;
        cin >> src;
        while (true) {
            int dst;
            cin >> dst;
            if (dst == -1)
                break;
            int w;
            cin >> w;
            adjacent[src].emplace_back(dst, w);
        }
    }

    for (int i = 1; i <= V; i++) {
        visit[i] = false;
    }
    visit[1] = true;
    DFS(1, 0);

    for (int i = 1; i <= V; i++) {
        visit[i] = false;
    }
    visit[maxDistNum] = true;
    DFS(maxDistNum, 0);

    cout << maxDist;
}