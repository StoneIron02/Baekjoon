#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b, int gcdVal) {
	return (a * b / gcdVal);
}

int lcm(int a, int b) {
	int gcdVal = gcd(a, b);
	return lcm(a, b, gcdVal);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
}