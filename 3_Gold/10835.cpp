#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[2001];
int b[2001];
int dp[2001][2001];

int dynamic_programming(int i, int j) {
	if (i == n || j == n) // base
		return 0;

	if (dp[i][j] == -1) { // µî·Ï
		dp[i][j] = max(dynamic_programming(i + 1, j), dynamic_programming(i + 1, j + 1));
		if (a[i] > b[j])
			dp[i][j] = max(dp[i][j], dynamic_programming(i, j + 1) + b[j]);
		}
	return dp[i][j];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	fill(&dp[0][0], &dp[n][n], -1);
	cout << dynamic_programming(0, 0);
}