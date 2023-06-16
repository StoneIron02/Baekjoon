#include <iostream>

using namespace std;

#define INF 987654321;

int n;
int w[16][16];
int dp[1 << 16][16];

int TSP(int visited, int current) {
    if (visited == (1 << n) - 1) { // 모든 정점 방문
        if (w[current][0] != 0) { // 여기서 시작 정점으로 갈 수 있는 경우
            return w[current][0];
        }
        return INF;
    }

    if (dp[visited][current] != 0) // 이미 계산한 경우
        return dp[visited][current];

    // 최소 비용 계산
    int minCost = INF;
    for (int i = 0; i < n; i++) {
        if (w[current][i] == 0) continue; // 경로 없음
        if (visited & (1 << i)) continue; // 이미 방문 했음

        int cost = w[current][i] + TSP(visited | (1 << i), i);
        minCost = min(minCost, cost);
    }
    dp[visited][current] = minCost;
    return minCost;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    int minCost = TSP(1, 0);
    cout << minCost;
}