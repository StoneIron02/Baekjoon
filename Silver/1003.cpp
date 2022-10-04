#include <iostream>
using namespace std;

pair<int, int> fib[40 + 1];

void fibonacci(int n) {
	for (int i = 2; i <= n; i++) {
		fib[i].first = fib[i - 1].first + fib[i - 2].first;
		fib[i].second = fib[i - 1].second + fib[i - 2].second;
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	fib[0] = { 1, 0 };
	fib[1] = { 0, 1 };

	fibonacci(40);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << fib[n].first << " " << fib[n].second << "\n";
	}
}