#include <iostream>
#include <cmath>
using namespace std;

int mod(int x, int y) {
	int result = x;
	while (true) {
		int sub = result - y;
		if (abs(sub) > abs(result)) {
			break;
		}
		result = sub;
	}

	return result;
}

int after(int x, int y) {
	int result = x;
	while (result < 0) {
		result += y;
	}
	while (result > y) {
		result -= y;
	}

	return result;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int m = mod(a, c);
	int p = pow(m, b);
	int r = after(p, c);
	cout << r;
}

// P = A^B * Q + R

// a  b  c
// 10 11 12
// 10 * 10 * 10 * ... * 10
// (11¹ø)
// -2 * -2 * ... * (11¹ø)