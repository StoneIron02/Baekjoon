#include <iostream>
using namespace std;

int* arr;

int fib(int n) {
	arr[1] = 1, arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	return arr[n];
}

int main() {
	int n;
	cin >> n;
	arr = new int[n + 1];
	cout << fib(n);
}