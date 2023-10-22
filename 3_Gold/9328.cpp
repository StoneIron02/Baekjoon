#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int h, w;
char matrix[102][102];
bool visit[102][102];
bool haveKey[26];
queue<pair<int, int>> door[26];
int maxCnt = 0;

string dx = "0211";
string dy = "1102";

void BFS(pair<int, int> s) {
    queue<pair<int, int>> queue;
    visit[s.first][s.second] = true;
    queue.push(s);

    while (!queue.empty()) {
        auto pos = queue.front();
        queue.pop();

        for (int t = 0; t < 4; t++) {
            int curDx = pos.first + (dx[t] - '1');
            int curDy = pos.second + (dy[t] - '1');

            if (curDx < 0 || curDx > h + 1) continue;
            if (curDy < 0 || curDy > w + 1) continue;
            if (matrix[curDx][curDy] == '*') continue;
            if (visit[curDx][curDy]) continue;

            if (matrix[curDx][curDy] >= 'A' && matrix[curDx][curDy] <= 'Z') {
                if (!haveKey[matrix[curDx][curDy] - 'A']) {
                    visit[curDx][curDy] = true;
                    door[matrix[curDx][curDy] - 'A'].push({curDx, curDy});
                    continue;
                }
            }

            if (matrix[curDx][curDy] >= 'a' && matrix[curDx][curDy] <= 'z') {
                if (!haveKey[matrix[curDx][curDy] - 'a']) {
                    while (!door[matrix[curDx][curDy] - 'a'].empty()) {
                        auto top = door[matrix[curDx][curDy] - 'a'].front();
                        queue.push({top.first, top.second});
                        door[matrix[curDx][curDy] - 'a'].pop();
                    }
                }
                haveKey[matrix[curDx][curDy] - 'a'] = true;
            }

            if (matrix[curDx][curDy] == '$') {
                maxCnt++;
            }

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
        for (int i = 0; i <= 101; i++) {
            for (int j = 0; j <= 101; j++) {
                matrix[i][j] = '.';
                visit[i][j] = false;
            }
        }
        for (int i = 0; i < 26; i++) {
            haveKey[i] = false;
            while (!door[i].empty()) {
                door[i].pop();
            }
        }
        maxCnt = 0;

        cin >> h >> w;
        cin.ignore();
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                matrix[i][j] = (char)cin.get();
            }
            cin.ignore();
        }

        string str;
        cin >> str;
        if (str != "0") {
            for (char c : str) {
                haveKey[c - 'a'] = true;
            }
        }

        BFS({0, 0});
        cout << maxCnt << "\n";
    }
}