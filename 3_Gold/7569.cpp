#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n, h;
int box[100][100][100];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h;
    queue<tuple<int, int, int>> queue;
    int numNonRipe = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 0)
                    numNonRipe++;
                if (box[i][j][k] == 1)
                    queue.push({i, j, k});
            }
        }
    }

    int day = 0;
    while (numNonRipe > 0 && !queue.empty()) {
        day++;
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            tuple<int, int, int> pos = queue.front();
            int r = get<0>(pos);
            int c = get<1>(pos);
            int l = get<2>(pos);
            queue.pop();

            if (r - 1 >= 0 && box[r - 1][c][l] == 0) {
                box[r - 1][c][l] = 1;
                numNonRipe--;
                queue.push({r - 1, c, l});
            }
            if (r + 1 < n && box[r + 1][c][l] == 0) {
                box[r + 1][c][l] = 1;
                numNonRipe--;
                queue.push({r + 1, c, l});
            }
            if (c - 1 >= 0 && box[r][c - 1][l] == 0) {
                box[r][c - 1][l] = 1;
                numNonRipe--;
                queue.push({r, c - 1, l});
            }
            if (c + 1 < m && box[r][c + 1][l] == 0) {
                box[r][c + 1][l] = 1;
                numNonRipe--;
                queue.push({r, c + 1, l});
            }
            if (l - 1 >= 0 && box[r][c][l - 1] == 0) {
                box[r][c][l - 1] = 1;
                numNonRipe--;
                queue.push({r, c, l - 1});
            }
            if (l + 1 < h && box[r][c][l + 1] == 0) {
                box[r][c][l + 1] = 1;
                numNonRipe--;
                queue.push({r, c, l + 1});
            }
        }
    }

    if (numNonRipe > 0)
        cout << -1;
    else
        cout << day;
}