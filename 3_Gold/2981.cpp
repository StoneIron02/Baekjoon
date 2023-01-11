#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	int curVal = 0, prevVal = 0;
	int gcdVal = 0;
	for (int i = 0; i < n; i++) {
		prevVal = curVal;
		cin >> curVal;
		if (i == 0) continue;
		if (i == 1) {
			gcdVal = abs(curVal - prevVal);
			continue;
		}
		gcdVal = gcd(gcdVal, abs(curVal - prevVal));
	}

	set<int> result;
	for (int i = 2; i <= sqrt(gcdVal); i++) {
		if (gcdVal % i == 0) {
			result.insert(i);
			result.insert(gcdVal / i);
		}
	}
	result.insert(gcdVal);

	for (auto i : result)
		cout << i << " ";
}