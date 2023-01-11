#include <iostream>
using namespace std;

long long* arr;

long long p(int n) {
	arr[1] = 1, arr[2] = 1, arr[3] = 1;
	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}
	return arr[n];
}

int main() {
	arr = new long long[101];
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << p(n) << "\n";
	}
}