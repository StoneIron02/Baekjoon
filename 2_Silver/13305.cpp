#include <iostream>
using namespace std;

unsigned long long greedy(int* path, int* price, int n) {
	int min = price[0];
	unsigned long long totalPrice = 0;
	for (int i = 0; i < n - 1; i++) {
		min = (price[i] < min ? price[i] : min);
		totalPrice += path[i] * (unsigned long long)min;
	}
	return totalPrice;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int* path = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
		cin >> path[i];
	int* price = new int[n];
	for (int i = 0; i < n; i++)
		cin >> price[i];
	cout << greedy(path, price, n);
}