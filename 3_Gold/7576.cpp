#include <iostream>
#include <queue>

using namespace std;

int m, n;
int box[1000][1000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    queue<pair<int, int>> queue;
    int numNonRipe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 0)
                numNonRipe++;
            if (box[i][j] == 1)
                queue.push({i, j});
        }
    }

    int day = 0;
    while (numNonRipe > 0 && !queue.empty()) {
        day++;
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> pos = queue.front();
            int r = pos.first;
            int c = pos.second;
            queue.pop();

            if (r - 1 >= 0 && box[r - 1][c] == 0) {
                box[r - 1][c] = 1;
                numNonRipe--;
                queue.push({r - 1, c});
            }
            if (r + 1 < n && box[r + 1][c] == 0) {
                box[r + 1][c] = 1;
                numNonRipe--;
                queue.push({r + 1, c});
            }
            if (c - 1 >= 0 && box[r][c - 1] == 0) {
                box[r][c - 1] = 1;
                numNonRipe--;
                queue.push({r, c - 1});
            }
            if (c + 1 < m && box[r][c + 1] == 0) {
                box[r][c + 1] = 1;
                numNonRipe--;
                queue.push({r, c + 1});
            }
        }
    }

    if (numNonRipe > 0)
        cout << -1;
    else
        cout << day;
}