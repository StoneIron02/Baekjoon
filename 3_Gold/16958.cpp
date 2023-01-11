#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> city(1001);
vector<vector<int>> dist(1001);
vector<bool> isSpecial(1001);

void Floyd_Warshall(int n, int t) {
	// 테이블 제작
	for (int i = 1; i <= n; i++) {
		dist[i] = vector<int>(n + 1);
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
			if (isSpecial[i] && isSpecial[j])
				dist[i][j] = t < dist[i][j] ? t : dist[i][j];
		}
	}

	// 모든 경로 탐색
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = dist[i][k] + dist[k][j] < dist[i][j] ? dist[i][k] + dist[k][j] : dist[i][j];
			}
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		isSpecial[i] = s;
		city[i] = { x, y };
	}
	Floyd_Warshall(n, t);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << "\n";
	}
}