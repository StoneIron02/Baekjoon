#include <iostream>
using namespace std;

int* arr;
int* dp;

int dynamic_programming(int n) {
	dp = new int[501] {0};
	for (int i = 1; i <= 500; i++) {
		if (arr[i] == 0) continue;
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = (dp[i] < dp[j] + 1 ? dp[j] + 1 : dp[i]);
		}
	}
	int max = -1;
	for (int i = 1; i <= 500; i++) {
		max = (dp[i] > max ? dp[i] : max);
	}
	return (n - max);
}

int main() {
	int n;
	cin >> n;
	arr = new int[501] {0};
	for (int i = 1; i <= n; i++) {
		int key, value;
		cin >> key >> value;
		arr[key] = value;
	}
	cout << dynamic_programming(n);
}