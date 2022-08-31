#include <iostream>
using namespace std;

int** arr;

int sum(int n) {
	int max = -1;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++) {
			int num;
			cin >> num;
			if (i == 0) {
				arr[i][j] = num;
				max < arr[i][j] ? max = arr[i][j] : max = max;
				continue;
			}
			if (j == 0)
				arr[i][j] = arr[i - 1][j] + num;
			else if (j == i)
				arr[i][j] = arr[i - 1][j - 1] + num;
			else
				arr[i][j] = (arr[i - 1][j - 1] > arr[i - 1][j] ? arr[i - 1][j - 1] : arr[i - 1][j]) + num;
			max < arr[i][j] ? max = arr[i][j] : max = max;
		}
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	cout << sum(n);
}