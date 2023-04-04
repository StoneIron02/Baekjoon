#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int V;
int matrix[26][26];
bool visit[26][26];
priority_queue<int, vector<int>, greater<>> complex;

void BFS(int i, int j) {
    queue<pair<int, int>> queue;
    int num = 0;
    queue.push({i, j});
    visit[i][j] = true;
    num++;

    while (!queue.empty()) {
        pair<int, int> v = queue.front();
        queue.pop();
        int r = v.first, c = v.second;
        if (r > 1 && matrix[r - 1][c] == 1 && !visit[r - 1][c]) {
            queue.push({r - 1, c});
            visit[r - 1][c] = true;
            num++;
        }
        if (r < V && matrix[r + 1][c] == 1 && !visit[r + 1][c]) {
            queue.push({r + 1, c});
            visit[r + 1][c] = true;
            num++;
        }
        if (c > 1 && matrix[r][c - 1] == 1 && !visit[r][c - 1]) {
            queue.push({r, c - 1});
            visit[r][c - 1] = true;
            num++;
        }
        if (c < V && matrix[r][c + 1] == 1 && !visit[r][c + 1]) {
            queue.push({r, c + 1});
            visit[r][c + 1] = true;
            num++;
        }
    }

    complex.push(num);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V;
    for (int i = 1; i <= V; i++) {
        cin.get();
        for (int j = 1; j <= V; j++) {
            matrix[i][j] = cin.get() - '0';
        }
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (matrix[i][j] == 1 && !visit[i][j]) {
                BFS(i, j);
            }
        }
    }

    cout << complex.size() << "\n";
    while (!complex.empty()) {
        cout << complex.top() << "\n";
        complex.pop();
    }
}