#include <iostream>

using namespace std;

int n;
int board[6][20][20]; // cur, x, y
bool update[6][20][20];
int maxBlock = 0;

void reset(int cur) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            update[cur][i][j] = false;
        }
    }
}

void backtracking(int cur, int maxCount) {
    if (cur == maxCount) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxBlock = max(maxBlock, board[cur][i][j]);
            }
        }
        return;
    }

    // left
    reset(cur + 1);
    for (int row = 0; row < n; row++) {
        int col = 0;
        for (int i = 0; i < n; i++) {
            int beforeData = board[cur][row][i];
            if (beforeData == 0) continue;
            if (col > 0 && !update[cur + 1][row][col - 1] && board[cur + 1][row][col - 1] == beforeData) {
                board[cur + 1][row][col - 1] *= 2;
                update[cur + 1][row][col - 1] = true;
                continue;
            }
            board[cur + 1][row][col++] = beforeData;
        }
        while (col < n) {
            board[cur + 1][row][col++] = 0;
        }
    }
    backtracking(cur + 1, maxCount);

    // right
    reset(cur + 1);
    for (int row = 0; row < n; row++) {
        int col = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int beforeData = board[cur][row][i];
            if (beforeData == 0) continue;
            if (col < n - 1 && !update[cur + 1][row][col + 1] && board[cur + 1][row][col + 1] == beforeData) {
                board[cur + 1][row][col + 1] *= 2;
                update[cur + 1][row][col + 1] = true;
                continue;
            }
            board[cur + 1][row][col--] = beforeData;
        }
        while (col >= 0) {
            board[cur + 1][row][col--] = 0;
        }
    }
    backtracking(cur + 1, maxCount);

    // up
    reset(cur + 1);
    for (int col = 0; col < n; col++) {
        int row = 0;
        for (int i = 0; i < n; i++) {
            int beforeData = board[cur][i][col];
            if (beforeData == 0) continue;
            if (row > 0 && !update[cur + 1][row - 1][col] && board[cur + 1][row - 1][col] == beforeData) {
                board[cur + 1][row - 1][col] *= 2;
                update[cur + 1][row - 1][col] = true;
                continue;
            }
            board[cur + 1][row++][col] = beforeData;
        }
        while (row < n) {
            board[cur + 1][row++][col] = 0;
        }
    }
    backtracking(cur + 1, maxCount);

    // down
    reset(cur + 1);
    for (int col = 0; col < n; col++) {
        int row = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int beforeData = board[cur][i][col];
            if (beforeData == 0) continue;
            if (row < n - 1 && !update[cur + 1][row + 1][col] && board[cur + 1][row + 1][col] == beforeData) {
                board[cur + 1][row + 1][col] *= 2;
                update[cur + 1][row + 1][col] = true;
                continue;
            }
            board[cur + 1][row--][col] = beforeData;
        }
        while (row >= 0) {
            board[cur + 1][row--][col] = 0;
        }
    }
    backtracking(cur + 1, maxCount);

}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[0][i][j];
        }
    }

    for (int maxCount = 1; maxCount <= 5; maxCount++) {
        backtracking(0, maxCount);
    }

    cout << maxBlock;
}