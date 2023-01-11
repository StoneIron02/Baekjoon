#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		unsigned long long result = 1;
		for (int i = 1; i <= b; i++) {
			result = (result * a) % 10;
		}

		if (result == 0)
			result = 10;

		cout << result << "\n";
	}
}