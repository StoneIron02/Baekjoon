#include <iostream>
#include <deque>
using namespace std;

int n, m;
bool matrix[101][101];
bool visit[101][101];
string dx = "0211";
string dy = "1102";

void BFS() {
    deque<pair<pair<int, int>, int>> deque;
    visit[1][1] = true;
    deque.push_back({{ 1, 1 }, 0});

    while (!deque.empty()) {
        auto top = deque.front();
        deque.pop_front();
        auto pos = top.first;
        auto breakCnt = top.second;

        if (pos.first == m && pos.second == n) {
            cout << breakCnt << "\n";
            break;
        }

        for (int i = 0; i < dx.size(); i++) {
            int curDx = pos.first + (dx[i] - '1');
            int curDy = pos.second + (dy[i] - '1');
            if (curDx < 1 || curDx > m) continue;
            if (curDy < 1 || curDy > n) continue;
            if (visit[curDx][curDy]) continue;
            visit[curDx][curDy] = true;

            if (!matrix[curDx][curDy]) { // gray
                deque.push_front({{curDx, curDy}, breakCnt});
            }
            else { // red
                deque.push_back({{curDx, curDy}, breakCnt + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = str[j - 1] - '0';
            visit[i][j] = false;
        }
    }
    BFS();
}