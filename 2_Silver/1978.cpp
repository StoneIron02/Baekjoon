#include <iostream>
using namespace std;

bool isPrime(int m) {
	for (int j = 2; j <= 1000; j++) {
		if (m % j == 0 && m != j)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	int count = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		if (m == 1) continue;
		if (isPrime(m))
			count++;
	}

	cout << count << endl;
}