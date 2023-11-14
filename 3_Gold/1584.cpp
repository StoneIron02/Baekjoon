#include <iostream>
#include <queue>

using namespace std;

int matrix[501][501];
int dist[501][501];
string dx = "0211";
string dy = "1102";
typedef pair<int, pair<int, int>> pipi;

void Dijkstra() {
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) {
            dist[i][j] = INT32_MAX;
        }
    }
    dist[0][0] = 0;
    priority_queue<pipi, vector<pipi>, greater<>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        auto pos = top.second;
        auto d = top.first;

        for (int i = 0; i < dx.size(); i++) {
            int curDx = pos.first + (dx[i] - '1');
            int curDy = pos.second + (dy[i] - '1');
            if (curDx < 0 || curDx > 500) continue;
            if (curDy < 0 || curDy > 500) continue;
            if (matrix[curDx][curDy] == 2) continue;
            if (matrix[curDx][curDy] == 1) {
                if (dist[curDx][curDy] > d + 1) {
                    dist[curDx][curDy] = d + 1;
                    pq.push({dist[curDx][curDy], {curDx, curDy}});
                }
            } else {
                if (dist[curDx][curDy] > d) {
                    dist[curDx][curDy] = d;
                    pq.push({dist[curDx][curDy], {curDx, curDy}});
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                matrix[x][y] = 1;
            }
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = min(x1, x2); x <= max(x1, x2); x++) {
            for (int y = min(y1, y2); y <= max(y1, y2); y++) {
                matrix[x][y] = 2;
            }
        }
    }
    Dijkstra();
    if (dist[500][500] == INT32_MAX) {
        cout << -1;
    } else {
        cout << dist[500][500];
    }
}