#include <iostream>
using namespace std;

int R, C;
char board[21][21];
bool visit[26];
int maxCnt = 0;
string dx = "0211";
string dy = "1102";

void backtracking(int curCnt, int curX, int curY) {
    bool flag = false;
    for (int i = 0; i < dx.size(); i++) {
        int curDx = curX + (dx[i] - '1');
        int curDy = curY + (dy[i] - '1');
        if (curDx < 1 || curDx > R) continue;
        if (curDy < 1 || curDy > C) continue;
        char c = board[curDx][curDy];
        if (visit[c - 'A']) continue;
        visit[c - 'A'] = true;
        flag = true;
        backtracking(curCnt + 1, curDx, curDy);
        visit[c - 'A'] = false;
    }
    if (!flag)
        maxCnt = max(maxCnt, curCnt);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> board[i][j];
        }
    }

    visit[board[1][1] - 'A'] = true;
    backtracking(1, 1, 1);
    cout << maxCnt;
}