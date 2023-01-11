#include <iostream>
using namespace std;

int* dp;

int dynamic_programming(int n) {
	dp = new int[n + 1];
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = (dp[i / 3] + 1 < dp[i] ? dp[i / 3] + 1 : dp[i]);
		if (i % 2 == 0)
			dp[i] = (dp[i / 2] + 1 < dp[i] ? dp[i / 2] + 1 : dp[i]);
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << dynamic_programming(n);
}