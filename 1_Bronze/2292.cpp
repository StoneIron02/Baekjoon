#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	int a = (n - 2) / 6;

	int m = 0;
	int w = 1;
	while (true) {
		for (int i = 0; i < w; i++) {
			if (m == a) {
				cout << w + 1 << endl;
				return 0;
			}
			m++;
		}
		w++;
	}
}
