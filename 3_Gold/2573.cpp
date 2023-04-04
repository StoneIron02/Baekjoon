#include <iostream>
#include <vector>
#include <queue>

int N, M;
int map[301][301];
int temp[301][301];
bool visit[301][301];

using namespace std;

void BFS(pair<int, int> s) {
    queue<pair<int, int>> queue;
    visit[s.first][s.second] = true;
    queue.push(s);

    while (!queue.empty()) {
        pair<int, int> u = queue.front();
        queue.pop();

        // 다음 빙산 높이 갱신
        int minus = 0;
        if (u.first > 1 && map[u.first - 1][u.second] == 0)
            minus++;
        if (u.first < N && map[u.first + 1][u.second] == 0)
            minus++;
        if (u.second > 1 && map[u.first][u.second - 1] == 0)
            minus++;
        if (u.second < M && map[u.first][u.second + 1] == 0)
            minus++;
        temp[u.first][u.second] = map[u.first][u.second] - minus;
        if (temp[u.first][u.second] < 0)
            temp[u.first][u.second] = 0;

        // BFS 방문 처리
        if (u.first > 1 && map[u.first - 1][u.second] != 0 && !visit[u.first - 1][u.second]) {
            visit[u.first - 1][u.second] = true;
            queue.push({u.first - 1, u.second});
        }
        if (u.first < N && map[u.first + 1][u.second] != 0 && !visit[u.first + 1][u.second]) {
            visit[u.first + 1][u.second] = true;
            queue.push({u.first + 1, u.second});
        }
        if (u.second > 1 && map[u.first][u.second - 1] != 0 && !visit[u.first][u.second - 1]) {
            visit[u.first][u.second - 1] = true;
            queue.push({u.first, u.second - 1});
        }
        if (u.second < M && map[u.first][u.second + 1] != 0 && !visit[u.first][u.second + 1]) {
            visit[u.first][u.second + 1] = true;
            queue.push({u.first, u.second + 1});
        }
    }
}

int BFS(int cur) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            temp[i][j] = map[i][j];
            visit[i][j] = false;
        }
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] != 0 && !visit[i][j]) {
                count++;
                BFS({i, j});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            map[i][j] = temp[i][j];
        }
    }

    if (count == 0)
        return 0;
    else if (count >= 2)
        return cur;
    else
        return BFS(cur + 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    cout << BFS(0);
}