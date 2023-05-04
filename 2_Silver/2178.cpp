#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int matrix[101][101];
int dist[101][101];
string dr = "0211", dc = "1102";

void BFS() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dist[i][j] = INT32_MAX;
        }
    }
    dist[1][1] = 1;
    queue<pair<int, int>> queue;
    queue.push({1, 1});

    while (!queue.empty()) {
        pair<int, int> pos = queue.front();
        queue.pop();

        for (int i = 0; i < dr.size(); i++) {
            int r = pos.first + (dr[i] - '1');
            int c = pos.second + (dc[i] - '1');
            if (r < 1 || r > N) continue;
            if (c < 1 || c > M) continue;
            if (matrix[r][c] && dist[r][c] > dist[pos.first][pos.second] + 1) {
                dist[r][c] = dist[pos.first][pos.second] + 1;
                queue.push({r, c});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++) {
            matrix[i][j] = str[j - 1] - '0';
        }
    }

    BFS();
    cout << dist[N][M];
}