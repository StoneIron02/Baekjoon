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
	int circumference; // PI´Â »ý·«
	cin >> circumference;
	circumference *= 2;

	vector<int> rs;
	for (int i = 1; i < n; i++) {
		int r;
		cin >> r;
		rs.push_back(r);
	}

	for (int i = 0; i < rs.size(); i++) {
		int num = rs[i] * 2;
		int gcdVal = gcd(circumference, num);
		cout << (circumference / gcdVal) << "/" << (num / gcdVal) << "\n";
	}
}