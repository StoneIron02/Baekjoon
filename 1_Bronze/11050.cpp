#include <iostream>
using namespace std;

int binomial_coefficient(int n, int k) {
	int mul = 1, div = 1;
	for (int i = n; i >= n - k + 1; i--)
		mul *= i;
	for (int i = k; i >= 1; i--)
		div *= i;
	return (mul / div);
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << binomial_coefficient(n, k);
}