#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int* cards = new int[n];
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cards[i] = num;
	}

	int max = 0;
	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			for (int c = b + 1; c < n; c++) {
				int sum = cards[a] + cards[b] + cards[c];
				if (sum > m) continue;
				max < sum ? max = sum : max = max;
			}
		}
	}

	cout << max << endl;
}