#include <iostream>
#include <queue>

using namespace std;

int n;
int dist[125][125];
int matrix[125][125];
string dx = "0211";
string dy = "1102";
typedef pair<int, pair<int, int>> pipi;

void Dijkstra() {
    priority_queue<pipi, vector<pipi>, greater<>> pq;
    dist[0][0] = matrix[0][0];
    pq.push({dist[0][0], {0, 0}});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        auto d = top.first;
        auto pos = top.second;

        for (int i = 0; i < 4; i++) {
            int curDx = pos.first + (dx[i] - '1');
            int curDy = pos.second + (dy[i] - '1');
            if (curDx < 0 || curDx > n - 1) continue;
            if (curDy < 0 || curDy > n - 1) continue;
            if (dist[curDx][curDy] > d + matrix[curDx][curDy]) {
                dist[curDx][curDy] = d + matrix[curDx][curDy];
                pq.push({dist[curDx][curDy], {curDx, curDy}});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                dist[i][j] = INT32_MAX;
            }
        }

        Dijkstra();
        cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
        t++;
    }
}