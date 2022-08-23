#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	vector<int> list;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		list.push_back(num);
	}

	int gcdVal = abs(list[0] - list[1]);
	for (int i = 2; i < list.size(); i++) {
		gcdVal = gcd(gcdVal, abs(list[i] - list[i - 1]));
	}

	for (int i = 2; i <= gcdVal; i++) {
		if (gcdVal % i == 0)
			cout << i << " ";
	}
}