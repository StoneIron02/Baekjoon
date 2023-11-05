#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string dx = "02110022";
string dy = "11020202";

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        int cnt = 0;
        bool matrix[51][51] {false };
        bool visit[51][51] {false };

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (matrix[i][j] && !visit[i][j]) {
                    cnt++;
                    queue<pair<int, int>> queue;
                    visit[i][j] = true;
                    queue.push({i, j});

                    while (!queue.empty()) {
                        auto top = queue.front();
                        queue.pop();

                        for (int k = 0; k < dx.size(); k++) {
                            int curDx = top.first + (dx[k] - '1');
                            int curDy = top.second + (dy[k] - '1');
                            if (curDx < 1 || curDx > h) continue;
                            if (curDy < 1 || curDy > w) continue;
                            if (!matrix[curDx][curDy]) continue;
                            if (visit[curDx][curDy]) continue;

                            visit[curDx][curDy] = true;
                            queue.push({curDx, curDy});
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}