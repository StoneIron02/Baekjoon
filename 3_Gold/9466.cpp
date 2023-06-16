#include <iostream>
#include <vector>

using namespace std;

int n;
bool visit[100'001];
bool finish[100'001];
bool result[100'001];
vector<int> edge[100'001];

int DFS(int cur) {
    auto v = edge[cur][0];
    if (visit[v] && !finish[v]) {
        // cycle
        result[cur] = false;
        finish[cur] = true;
        if (cur == v)
            return -1;
        return v;
    }
    if (!visit[v]) {
        visit[v] = true;
        int cycleNum = DFS(v);
        if (cycleNum > -1) {
            result[cur] = false;
        }
        finish[cur] = true;
        if (cycleNum == cur) {
            return -1;
        } else {
            return cycleNum;
        }
    }
    finish[cur] = true;
    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            edge[i].clear();
            visit[i] = false;
            finish[i] = false;
            result[i] = true;
            int j;
            cin >> j;
            edge[i].push_back(j);
        }

        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                int cycleNum = DFS(i);
                if (cycleNum > -1)
                    result[i] = false;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (result[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}