#include <iostream>
using namespace std;

int n;
int dp[3][100001]{ 0 };
int arr[3][100001]{ 0 };

void dynammic_programming() {
	dp[1][1] = arr[1][1];
	dp[2][1] = arr[2][1];
	for (int i = 2; i <= n; i++) {
		int mx = dp[1][i - 2] > dp[2][i - 2] ? dp[1][i - 2] : dp[2][i - 2];
		dp[1][i] = dp[2][i - 1] > mx ? dp[2][i - 1] : mx;
		dp[1][i] += arr[1][i];
		dp[2][i] = dp[1][i - 1] > mx ? dp[1][i - 1] : mx;
		dp[2][i] += arr[2][i];
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> arr[1][j];
		for (int j = 1; j <= n; j++)
			cin >> arr[2][j];
		dynammic_programming();
		cout << (dp[1][n] > dp[2][n] ? dp[1][n] : dp[2][n]) << "\n";
	}
}