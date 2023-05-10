#include <iostream>

using namespace std;

int n, m;
int dist[101][101];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = 200;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int num, sum = 200;
    for (int i = 1; i <= n; i++) {
        int curSum = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            curSum += dist[i][j];
        }
        if (curSum < sum) {
            num = i;
            sum = curSum;
        }
    }
    cout << num;
}