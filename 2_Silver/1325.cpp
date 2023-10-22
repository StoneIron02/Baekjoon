#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int n, m;
bool visit[10001];
vector<int> edges[10001];

int BFS(int s) {
    for (int i = 0; i <= 10000; i++) {
        visit[i] = false;
    }
    queue<int> queue;
    int cnt = 1;
    visit[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (auto v : edges[top]) {
            if (!visit[v]) {
                cnt++;
                visit[v] = true;
                queue.push(v);
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[b].push_back(a);
    }

    int maxCnt = -1;
    set<int> results;
    for (int i = 1; i <= n; i++) {
        int result = BFS(i);
        if (maxCnt < result) {
            maxCnt = result;
            results.clear();
        }
        if (maxCnt == result) {
            results.insert(i);
        }
    }

    for (auto v : results) {
        cout << v << " ";
    }
}