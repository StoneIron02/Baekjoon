#include <iostream>
using namespace std;

long long** dp;

int dynamic_programming(int n) {
	dp = new long long*[n + 1];
	dp[1] = new long long[10]{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for (int i = 2; i <= n; i++) {
		dp[i] = new long long[10];
		dp[i][0] = dp[i - 1][1] % 1000000000;
		dp[i][9] = dp[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	long long sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += dp[n][j];
	}
	return sum % 1000000000;
}

int main() {
	int n;
	cin >> n;
	cout << dynamic_programming(n);
}