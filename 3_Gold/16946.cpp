#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m;
int matrix[1001][1001];
bool visit[1001][1001];
int group[1001][1001];
vector<int> groupCount;
string dx = "0211";
string dy = "1102";

int BFS(int sx, int sy, int groupNum) {
    queue<pair<int, int>> queue;
    visit[sx][sy] = true;
    queue.push({sx, sy});
    group[sx][sy] = groupNum;
    int cnt = 1;
    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (int i = 0; i < dx.size(); i++) {
            int curDx = top.first + (dx[i] - '1');
            int curDy = top.second + (dy[i] - '1');
            if (curDx < 1 || curDx > n) continue;
            if (curDy < 1 || curDy > m) continue;
            if (visit[curDx][curDy]) continue;
            if (matrix[curDx][curDy]) continue;
            visit[curDx][curDy] = true;
            group[curDx][curDy] = groupNum;
            cnt++;
            queue.push({curDx, curDy});
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int num = cin.get() - '0';
            matrix[i][j] = num;
        }
        cin.ignore();
    }

    int groupNum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j] == 0 && !visit[i][j]) {
                int cnt = BFS(i, j, groupNum);
                groupCount.push_back(cnt);
                groupNum++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j] == 1) {
                set<int> groups;
                int sum = 1;
                for (int t = 0; t < dx.size(); t++) {
                    int curDx = i + (dx[t] - '1');
                    int curDy = j + (dy[t] - '1');
                    if (curDx < 1 || curDx > n) continue;
                    if (curDy < 1 || curDy > m) continue;
                    if (matrix[curDx][curDy]) continue;
                    if (groups.find(group[curDx][curDy]) != groups.end()) continue;
                    groups.insert(group[curDx][curDy]);
                    sum = (sum + groupCount[group[curDx][curDy]]) % 10;
                }
                cout << sum;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
}