#include <iostream>
using namespace std;

int* arr;
int* dp;

int sum(int n) {
	dp = new int[n + 1];
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 3] + arr[i - 1] > dp[i - 2] ? dp[i - 3] + arr[i - 1] : dp[i - 2]) + arr[i];
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	cout << sum(n);
}