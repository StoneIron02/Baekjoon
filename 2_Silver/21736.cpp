#include <iostream>
#include <queue>

using namespace std;

int n, m;
char matrix[601][601];
bool visit[601][601];
pair<int, int> s;
string dx = "0211";
string dy = "1102";

int BFS() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visit[i][j] = false;
        }
    }
    queue<pair<int, int>> queue;
    visit[s.first][s.second] = true;
    queue.push({s.first, s.second});

    int cnt = 0;
    while (!queue.empty()) {
        auto top = queue.front();
        queue.pop();

        for (int i = 0; i < dx.size(); i++) {
            int curDx = top.first + (dx[i] - '1');
            int curDy = top.second + (dy[i] - '1');
            if (curDx < 1 || curDx > n) continue;
            if (curDy < 1 || curDy > m) continue;
            if (matrix[curDx][curDy] == 'X') continue;
            if (visit[curDx][curDy]) continue;
            visit[curDx][curDy] = true;
            queue.push({curDx, curDy});
            if (matrix[curDx][curDy] == 'P')
                cnt++;
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'I')
                s = {i, j};
        }
    }
    int person = BFS();
    if (person == 0)
        cout << "TT";
    else
        cout << person;
}