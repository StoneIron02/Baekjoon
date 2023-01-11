#include <iostream>
using namespace std;

int n;
unsigned int arr[100001];
unsigned long long sum[100001] = { 0 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	unsigned long long max = 0;

	// 国 - 国 - 国烹
	for (int beeIndex = 2; beeIndex <= n - 1; beeIndex++) {
		unsigned long long cur = 0;
		cur += sum[n] - arr[1] - arr[beeIndex];
		cur += sum[n] - sum[beeIndex];
		max = cur > max ? cur : max;
	}

	// 国烹 - 国 - 国
	for (int beeIndex = 2; beeIndex <= n - 1; beeIndex++) {
		unsigned long long cur = 0;
		cur += sum[n] - arr[n] - arr[beeIndex];
		cur += sum[beeIndex - 1];
		max = cur > max ? cur : max;
	}

	// 国 - 国烹 - 国
	for (int beeBoxIndex = 2; beeBoxIndex <= n - 1; beeBoxIndex++) {
		unsigned long long cur = 0;
		cur += sum[beeBoxIndex] - sum[1];
		cur += sum[n - 1] - sum[beeBoxIndex - 1];
		max = cur > max ? cur : max;
	}

	cout << max;
}