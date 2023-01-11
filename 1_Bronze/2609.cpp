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
	int a, b;
	cin >> a >> b;
	int gcdVal = gcd(a, b);
	cout << gcdVal << "\n";
	cout << lcm(a, b, gcdVal) << "\n";
}