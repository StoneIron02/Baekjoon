#include <iostream>
using namespace std;

int*** arr;

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (a < b && b < c)
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int w2(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		a = 0, b = 0, c = 0;
	if (a > 20 || b > 20 || c > 20)
		a = 20, b = 20, c = 20;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (i <= 0 || j <= 0 || k <= 0)
					arr[i + 50][j + 50][k + 50] = 1;
				else if (i < j && j < k)
					arr[i + 50][j + 50][k + 50] = arr[i + 50][j + 50][k - 1 + 50] + arr[i + 50][j - 1 + 50][k - 1 + 50] - arr[i + 50][j - 1 + 50][k + 50];
				else
					arr[i + 50][j + 50][k + 50] = arr[i - 1 + 50][j + 50][k + 50] + arr[i - 1 + 50][j - 1 + 50][k + 50] + arr[i - 1 + 50][j + 50][k - 1 + 50] - arr[i - 1 + 50][j - 1 + 50][k - 1 + 50];
			}
		}
	}
	return arr[a + 50][b + 50][c + 50];
}

int main() {
	arr = new int** [71];
	for (int i = 0; i < 71; i++) {
		arr[i] = new int* [71];
		for (int j = 0; j < 71; j++) {
			arr[i][j] = new int[71];
		}
	}

	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w2(a, b, c) << "\n";
	}
}