#include <iostream>
using namespace std;

int arr[1001]{ 0 };
int sum[1001][1001]{ 0 };
int maxsum;

void dynamic(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cursum = sum[i][j - 1] + arr[j];
			sum[i][j] = cursum;
			maxsum = cursum > maxsum ? cursum : maxsum;
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int a = 0; a < t; a++) {
		int n;
		cin >> n;
		maxsum = -1001; 
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			arr[i] = num;
			sum[i][i] = num;
			maxsum = num > maxsum ? num : maxsum;
		}
		dynamic(n);
		cout << maxsum << "\n";
	}
}