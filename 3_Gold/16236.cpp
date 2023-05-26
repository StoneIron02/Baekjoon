#include <iostream>
#include <queue>

using namespace std;

int n;
int matrix[20][20];
int dist[20][20];
string dx = "0211";
string dy = "1102";
int sharkSize = 2;
int exp = 0;
int cnt = 0;

pair<int, int> BFS(pair<int, int> s) {
    queue<pair<int, int>> queue;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT32_MAX;
        }
    }
    dist[s.first][s.second] = 0;
    queue.push(s);

    while (!queue.empty()) {
        auto pos = queue.front();
        queue.pop();

        for (int i = 0; i < dx.size(); i++) {
            int curDx = dx[i] - '1';
            int curDy = dy[i] - '1';
            pair<int, int> newPos = {pos.first + curDx, pos.second + curDy};
            if (newPos.first < 0 || newPos.first > n - 1) continue; // out of index
            if (newPos.second < 0 || newPos.second > n - 1) continue; // out of index
            if (dist[newPos.first][newPos.second] <= dist[pos.first][pos.second] + 1) continue; // no minimum
            if (matrix[newPos.first][newPos.second] > sharkSize) continue; // can't visit

            dist[newPos.first][newPos.second] = dist[pos.first][pos.second] + 1;
            queue.push(newPos);
        }
    }

    int minDist = INT32_MAX;
    pair<int, int> minPos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0 && matrix[i][j] < sharkSize) {
                if (minDist > dist[i][j]) {
                    minDist = dist[i][j];
                    minPos = {i, j};
                }
            }
        }
    }

    if (minDist == INT32_MAX) // nothing can eat
        return {-1, -1};

    cnt += minDist;
    exp++;
    if (exp == sharkSize) {
        sharkSize++;
        exp = 0;
    }
    matrix[minPos.first][minPos.second] = 9;
    matrix[s.first][s.second] = 0;
    return minPos;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    pair<int, int> s;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 9)
                s = {i, j};
        }
    }

    while (s.first != -1) {
        s = BFS(s);
    }
    cout << cnt;
}