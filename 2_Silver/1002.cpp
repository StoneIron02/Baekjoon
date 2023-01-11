#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		double in = d - abs(r1 - r2);
		double out = d - (r1 + r2);
		if (d == 0 && r1 == r2)
			cout << -1 << "\n";
		else if (out < 0 && in > 0)
			cout << 2 << "\n";
		else if (out == 0 || in == 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}