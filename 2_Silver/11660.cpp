#include <iostream>
using namespace std;

int arr[1025][1025]{ 0 };
int dp[1025][1025]{ 0 };

void sum(int n) {
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		dp[1][i] = dp[1][i - 1] + arr[1][i];
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	sum(n);
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << result << "\n";
	}
}