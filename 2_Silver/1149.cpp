#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int** price = new int* [n];
	for (int i = 0; i < n; i++) {
		price[i] = new int[3];
		cin >> price[i][0] >> price[i][1] >> price[i][2];
	}

	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[3];
	}

	dp[0][0] = price[0][0];
	dp[0][1] = price[0][1];
	dp[0][2] = price[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1] + price[i][0], dp[i - 1][2] + price[i][0]);
		dp[i][1] = min(dp[i - 1][0] + price[i][1], dp[i - 1][2] + price[i][1]);
		dp[i][2] = min(dp[i - 1][0] + price[i][2], dp[i - 1][1] + price[i][2]);
	}

	int min = dp[n - 1][0];
	min > dp[n - 1][1] ? min = dp[n - 1][1] : min = min;
	min > dp[n - 1][2] ? min = dp[n - 1][2] : min = min;
	cout << min;

}

//cout << color(price, n, 1, -1, 0);
// 
// 
// 
//int color(int** price, int n, int i, int preNum, int sum) {
//	int sumRed = 10000000, sumGreen = 10000000, sumBlue = 10000000;
//
//	if (i > n) {
//		return sum;
//	}
//
//	if (preNum == -1) { // 1
//		sumRed = color(price, n, i + 1, 0, sum + price[i - 1][0]);
//		sumGreen = color(price, n, i + 1, 1, sum + price[i - 1][1]);
//		sumBlue = color(price, n, i + 1, 2, sum + price[i - 1][2]);
//	}
//	else if (preNum == 0) { //red
//		sumGreen = color(price, n, i + 1, 1, sum + price[i - 1][1]);
//		sumBlue = color(price, n, i + 1, 2, sum + price[i - 1][2]);
//	}
//	else if (preNum == 1) { //green
//		sumRed = color(price, n, i + 1, 0, sum + price[i - 1][0]);
//		sumBlue = color(price, n, i + 1, 2, sum + price[i - 1][2]);
//	}
//	else if (preNum == 2) { //blue
//		sumRed = color(price, n, i + 1, 0, sum + price[i - 1][0]);
//		sumGreen = color(price, n, i + 1, 1, sum + price[i - 1][1]);
//	}
//
//	int min = sumRed;
//	min > sumGreen ? min = sumGreen : min = min;
//	min > sumBlue ? min = sumBlue : min = min;
//	return min;
//}

// n  i  preNum  sum
// 3  2  0		 26
// 
// 3  3  1       86
// 3  3  2       83
// 
// 3  .  0       99
// 3  .  2       185
// 3  .  0       96
// 3  .  1       172
