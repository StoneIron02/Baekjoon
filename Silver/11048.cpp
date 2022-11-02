#include <iostream>
using namespace std;

int arr[1001][1001]{ 0 };
int dp[1001][1001]{ 0 };

void dynamic(int n, int m) {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			int max = dp[r - 1][c];
			max = dp[r][c - 1] > max ? dp[r][c - 1] : max;
			max = dp[r - 1][c - 1] > max ? dp[r - 1][c - 1] : max;
			dp[r][c] = max + arr[r][c];
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			cin >> arr[r][c];
		}
	}
	dynamic(n, m);
	cout << dp[n][m];
}