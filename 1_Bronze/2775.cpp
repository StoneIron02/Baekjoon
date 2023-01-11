#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k, n;
		cin >> k;
		cin >> n;

		double sum = 1;
		for (int j = 0; j < n - 1; j++) {
			sum *= (k + n - j);
			sum /= (j + 1);
		}

		cout << (int)sum << endl;
	}
}