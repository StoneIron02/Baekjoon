#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool matrix[101][101];
bool visit[101][101];
string dx = "0211";
string dy = "1102";

void BFS(pair<int, int> s, int cnt) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visit[i][j] = false;
        }
    }

    vector<pair<int, int>> change;
    queue<pair<int, int>> queue;
    queue.push({s.first, s.second});
    visit[s.first][s.second] = true;

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (int i = 0; i < dx.size(); i++) {
            int curDx = top.first + (dx[i] - '1');
            int curDy = top.second + (dy[i] - '1');
            if (curDx < 1 || curDy < 1) continue;
            if (curDx > n || curDy > m) continue;
            if (visit[curDx][curDy]) continue;
            if (matrix[curDx][curDy]) continue;
            visit[curDx][curDy] = true;
            queue.push({curDx, curDy});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visit[i][j]) {
                int num = 0;
                for (int d = 0; d < dx.size(); d++) {
                    int curDx = i + (dx[d] - '1');
                    int curDy = j + (dy[d] - '1');
                    if (visit[curDx][curDy]) num++;
                }
                if (num >= 2) {
                    change.emplace_back(i, j);
                }
            }
        }
    }

    if (change.empty()) {
        cout << cnt;
        return;
    }
    for (auto pos : change) {
        matrix[pos.first][pos.second] = 0;
    }
    BFS(s, cnt + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }

    BFS({1, 1}, 0);
}