#include <iostream>
using namespace std;

int* arr;

int sum(int n) {
	int max = -1000;
	arr[0] = -1000;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		num > max ? max = num : max = max;
		arr[i] = (arr[i - 1] + num > num ? arr[i - 1] + num : num);
		arr[i] > max ? max = arr[i] : max = max;
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	arr = new int[n + 1];
	cout << sum(n);
}