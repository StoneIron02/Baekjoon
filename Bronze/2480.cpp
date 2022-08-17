#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}
	else if (a == b) {
		cout << 1000 + a * 100;
	}
	else if (b == c) {
		cout << 1000 + b * 100;
	}
	else if (c == a) {
		cout << 1000 + c * 100;
	}
	else {
		int max = a;
		max < b ? max = b : max = max;
		max < c ? max = c : max = max;
		cout << max * 100;
	}
}