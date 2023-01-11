#include <iostream>
using namespace std;

int dp[16][16] {0};

void dynamic(int startR, int startC, int endR, int endC, int k) {
	if (k != 0) {
		int k_r = (k - 1) / endC + 1;
		int k_c = (k - 1) % endC + 1;
		dynamic(startR, startC, k_r, k_c, 0);
		dynamic(k_r, k_c, endR, endC, 0);
		return;
	}
	for (int r = startR; r <= endR; r++) {
		for (int c = startC; c <= endC; c++) {
			if (r == startR && c == startC)
				continue;
			else if (r == startR)
				dp[r][c] = dp[r][c - 1];
			else if (c == startC)
				dp[r][c] = dp[r - 1][c];
			else
				dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][1] = 1;
	dynamic(1, 1, n, m, k);
	cout << dp[n][m];
}