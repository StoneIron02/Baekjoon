#include <iostream>
using namespace std;

unsigned long mod(int a, int b, int c) {
	if (b == 1) return a % c;

	unsigned long long modNum = mod(a, b / 2, c);

	if (b % 2 == 1)
		return (modNum * modNum) % c * a % c;
	else
		return (modNum * modNum) % c;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << mod(a, b, c);
}