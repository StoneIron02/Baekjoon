#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool visit[100];
vector<int> edges1[100];
vector<int> edges2[100];

int BFS1(int s) {
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    visit[s] = true;
    queue<int> q;
    q.push(s);

    int cnt = 0;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        for (auto v : edges1[top]) {
            if (!visit[v]) {
                visit[v] = true;
                cnt++;
                q.push(v);
            }
        }
    }

    return cnt;
}

int BFS2(int s) {
    for (int i = 1; i <= n; i++) {
        visit[i] = false;
    }
    visit[s] = true;
    queue<int> q;
    q.push(s);

    int cnt = 0;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        for (auto v : edges2[top]) {
            if (!visit[v]) {
                visit[v] = true;
                cnt++;
                q.push(v);
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
        edges1[a].push_back(b);
        edges2[b].push_back(a);
    }
    int half = n / 2, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (BFS1(i) > half || BFS2(i) > half) {
            cnt++;
        }
    }
    cout << cnt;
}