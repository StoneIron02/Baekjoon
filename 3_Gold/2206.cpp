#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
bool matrix[1001][1001];
int dist[1001][1001][2];

string dx = "0211";
string dy = "1102";

void BFS() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = INT32_MAX;
            }
        }
    }
    queue<pair<pair<int, int>, bool>> queue;
    dist[1][1][0] = 0;
    queue.push({{1, 1}, 0});

    while (!queue.empty()) {
        auto top = queue.front();
        auto u = top.first;
        auto isBroak = top.second;
        queue.pop();

        if (u.first == n && u.second == m) {
            break;
        }

        for (int i = 0; i < dx.size(); i++) {
            int curDx = dx[i] - '1';
            int curDy = dy[i] - '1';
            if (u.first + curDx < 1 || u.first + curDx > n) continue; // out of index
            if (u.second + curDy < 1 || u.second + curDy > m) continue; // out of index
            if (matrix[u.first + curDx][u.second + curDy]) { // wall
                if (isBroak) continue;
                if (dist[u.first + curDx][u.second + curDy][1] > dist[u.first][u.second][isBroak] + 1) {
                    dist[u.first + curDx][u.second + curDy][1] = dist[u.first][u.second][isBroak] + 1;
                    queue.push({{u.first + curDx, u.second + curDy}, true});
                }
                if (dist[u.first + curDx][u.second + curDy][0] > dist[u.first][u.second][isBroak] + 1) {
                    dist[u.first + curDx][u.second + curDy][0] = dist[u.first][u.second][isBroak] + 1;
                    queue.push({{u.first + curDx, u.second + curDy}, true});
                }
            }
            if (dist[u.first + curDx][u.second + curDy][isBroak] > dist[u.first][u.second][isBroak] + 1) {
                dist[u.first + curDx][u.second + curDy][isBroak] = dist[u.first][u.second][isBroak] + 1;
                queue.push({{u.first + curDx, u.second + curDy}, isBroak});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int value = cin.get() - '0';
            matrix[i][j] = value;
        }
        cin.ignore();
    }

    int minDist = INT32_MAX;
    BFS();
    minDist = min(dist[n][m][0], dist[n][m][1]);

    if (minDist == INT32_MAX)
        cout << -1;
    else
        cout << minDist + 1;
}