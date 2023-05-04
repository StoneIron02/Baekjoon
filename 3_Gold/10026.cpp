#include <iostream>
#include <queue>
#include <string>
#define R 1
#define G 2
#define B 3

using namespace std;

int n;
int matrix[101][101];
bool visit[101][101];
int num_distinguish = 0, num_non_distinguish = 0;
string dx = "0211";
string dy = "1102";

void BFS(pair<int, int> s, bool distinguish) {
    queue<pair<int, int>> queue;
    visit[s.first][s.second] = true;
    queue.push(s);

    while (!queue.empty()) {
        auto u = queue.front();
        queue.pop();
        for (int i = 0; i < dx.size(); i++) {
            int cur_dx = dx[i] - '1';
            int cur_dy = dy[i] - '1';
            if (u.first + cur_dx >= 1 && u.first + cur_dx <= n &&
                    u.second + cur_dy >= 1 && u.second + cur_dy <= n &&
                    !visit[u.first + cur_dx][u.second + cur_dy] &&
                    matrix[u.first + cur_dx][u.second + cur_dy] == matrix[u.first][u.second]) {
                visit[u.first + cur_dx][u.second + cur_dy] = true;
                queue.push({u.first + cur_dx, u.second + cur_dy});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == 'R')
                matrix[i][j] = R;
            else if (c == 'G')
                matrix[i][j] = G;
            else
                matrix[i][j] = B;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visit[i][j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visit[i][j]) {
                num_distinguish++;
                BFS({i, j}, true);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visit[i][j] = false;
            if (matrix[i][j] == G)
                matrix[i][j] = R;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visit[i][j]) {
                num_non_distinguish++;
                BFS({i, j}, false);
            }
        }
    }

    cout << num_distinguish << " " << num_non_distinguish;
}