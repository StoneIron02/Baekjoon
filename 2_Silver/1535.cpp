#include <iostream>
using namespace std;

int dp[21][101]{ 0 };
int arr[21][2];

void dynammic_programming(int n) {
	for (int i = 1; i <= n; i++) {
		int price = arr[i][0];
		for (int j = 1; j <= 100; j++) {
			int max = dp[i - 1][j];
			if (j - price > 0) {
				max = dp[i - 1][j] > max ? dp[i - 1][j] : max;
				max = dp[i - 1][j - price] + arr[i][1] > max ? dp[i - 1][j - price] + arr[i][1] : max;
			}
			dp[i][j] = max;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0];
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][1];
	}
	dynammic_programming(n);
	cout << dp[n][100];
}