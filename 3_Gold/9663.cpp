#include <iostream>

using namespace std;

/* 퀸은 가로, 세로, 대각선의 말을 공격할 수 있으므로, 같은 row에 두 개 이상의 퀸이 들어가면 안 된다.
 * 그런데 n개의 퀸을 n개의 row에 놓아야 하므로, 각 row에는 반드시 한 개의 퀸만 들어가야 한다.
 * 또한, row마다 퀸을 배치할 때, 기존에 배치한 퀸들과 같은 col에 있는지와
 * row 차이의 절댓값과 col 차이의 절댓값이 같은지(대각선에 있는지)를 확인해야 한다.
 */

int n;
int queens[15];
int result = 0;

bool canPlace(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (queens[i] == c) return false;
        if (abs(i - r) == abs(queens[i] - c)) return false;
    }
    return true;
}

void backtracking(int cur) {
    if (cur == n) {
        result++;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (canPlace(cur, j)) {
            queens[cur] = j;
            backtracking(cur + 1);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    backtracking(0);
    cout << result;
}