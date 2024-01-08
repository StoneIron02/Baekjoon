#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int h, w;
char matrix[101][101];
bool visit[101][101];
string dx = "0211";
string dy = "1102";

void BFS(pair<int, int> s) {
    queue<pair<int, int>> queue;
    visit[s.first][s.second] = true;
    queue.push(s);

    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int curDx = top.first + (dx[i] - '1');
            int curDy = top.second + (dy[i] - '1');
            if (curDx < 1 || curDx > h) continue;
            if (curDy < 1 || curDy > w) continue;
            if (matrix[curDx][curDy] == '.') continue;
            if (visit[curDx][curDy]) continue;

            visit[curDx][curDy] = true;
            queue.push({curDx, curDy});
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> matrix[i][j];
                visit[i][j] = false;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (matrix[i][j] != '.' && !visit[i][j]) {
                    BFS({i, j});
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}