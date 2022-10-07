#include <iostream>
using namespace std;

int fib(int n) {
	int mem[46]{ 0 };
	mem[0] = 0;
	mem[1] = 1;
	for (int i = 2; i <= n; i++)
		mem[i] = mem[i - 1] + mem[i - 2];
	return mem[n];
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	cout << fib(n);
}