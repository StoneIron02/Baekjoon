#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int w = 1;
	int n = 0;
	while (true) {
		for (int i = 1; i <= w; i++) {
			n++;
			if (x == n) {
 				if (w % 2 == 1) //È¦ - ³»¸²
					cout << (w + 1 - i) << "/" << i << endl;
				else // Â¦ - ¿À¸§
					cout << i << "/" << (w + 1 - i) << endl;
				return 0;
			}
		}
		w++;
	}
}