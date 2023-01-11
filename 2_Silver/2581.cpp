#include <iostream>
using namespace std;

bool isPrime(int num) {
	if (num == 1) return false;
	for (int j = 2; j <= 1000; j++) {
		if (num % j == 0 && num != j)
			return false;
	}
	return true;
}

int main() {
	int m, n;
	cin >> m >> n;

	int sum = -1;
	int first = 0;
	for (int i = m; i <= n; i++) {
		if (isPrime(i)) {
			if (sum == -1) {
				sum += 1;
				first = i;
			}
			sum += i;
		}
	}

	cout << sum << endl;
	if (sum != -1)
		cout << first << endl;
}