#include <iostream>
using namespace std;

int dp[1001]{ 0 };

void dynamic_programming(int n) {
	for (int i = 1; i <= n; i++) {
		int max = -1;
		for (int j = i / 2; j >= 0; j--) {
			int a = j;
			int b = i - j;
			max = dp[j] + dp[i - j] > max ? dp[j] + dp[i - j] : max;
		}
		dp[i] = max;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	dynamic_programming(n);
	cout << dp[n];
}