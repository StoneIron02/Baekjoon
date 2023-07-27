#include <iostream>
#include <queue>

using namespace std;

int n, m;
int matrix[1001][1001];
int dist[1001][1001];
pair<int, int> s;
string dx = "0211";
string dy = "1102";

void BFS() {
    queue<pair<int, int>> queue;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = INT32_MAX;
        }
    }
    dist[s.first][s.second] = 0;
    queue.push({s.first, s.second});

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (int i = 0; i < dx.size(); i++) {
            int curDx = top.first + (dx[i] - '1');
            int curDy = top.second + (dy[i] - '1');
            if (curDx < 1 || curDx > n) continue;
            if (curDy < 1 || curDy > m) continue;
            if (matrix[curDx][curDy] == 0) continue;
            if (dist[curDx][curDy] > dist[top.first][top.second] + 1) {
                dist[curDx][curDy] = dist[top.first][top.second] + 1;
                queue.push({curDx, curDy});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                s = {i, j};
            }
        }
    }

    BFS();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dist[i][j] == INT32_MAX) {
                if (matrix[i][j] == 0)
                    cout << 0 << " ";
                else
                    cout << -1 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}