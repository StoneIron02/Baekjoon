#include <iostream>
using namespace std;

int* arr;
int* dp;

int dynamic_programming(int n) {
	dp = new int[n + 1];
	int max = -1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = (dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i]);
			}
		}
		max = (dp[i] > max ? dp[i] : max);
	}
	return max;
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
	cout << dynamic_programming(n);
}