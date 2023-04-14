#include <iostream>
#include <string>
#include <queue>

using namespace std;

int T;
int M, N, K;
int map[50][50];
bool visit[50][50];
int result;

string dx = "0211";
string dy = "1102";

void BFS(pair<int, int> s) {
    queue<pair<int, int>> queue;
    visit[s.first][s.second] = true;
    queue.push(s);
    result++;

    while (!queue.empty()) {
        pair<int, int> u = queue.front();
        queue.pop();

        for (int i = 0; i < dx.size(); i++) {
            int cur_dx = dx[i] - '1';
            int cur_dy = dy[i] - '1';
            if ((u.first + cur_dx >= 0 && u.first + cur_dx < M) &&
                    (u.second + cur_dy >= 0 && u.second + cur_dy < N) &&
                    map[u.first + cur_dx][u.second + cur_dy] &&
                    !visit[u.first + cur_dx][u.second + cur_dy]) {
                visit[u.first + cur_dx][u.second + cur_dy] = true;
                queue.push({u.first + cur_dx, u.second + cur_dy});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = 0;
                visit[i][j] = false;
                result = 0;
            }
        }
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] && !visit[i][j])
                    BFS({i, j});
            }
        }

        cout << result << "\n";
    }
}