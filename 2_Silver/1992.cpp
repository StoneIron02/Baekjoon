#include <iostream>
using namespace std;

void divide_and_conquer(int** arr, int startI, int startJ, int n) {
	int num = arr[startI][startJ];
	if (n == 1) {
		cout << num;
		return;
	}
	for (int i = startI; i < startI + n; i++) {
		for (int j = startJ; j < startJ + n; j++) {
			if (num != arr[i][j]) {
				cout << "(";
				for (int newI = startI; newI < startI + n; newI += n / 2) {
					for (int newJ = startJ; newJ < startJ + n; newJ += n / 2) {
						divide_and_conquer(arr, newI, newJ, n / 2);
					}
				}
				cout << ")";
				return;
			}
		}
	}
	cout << num;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	cin.get();
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = cin.get() - '0';
		}
		cin.get();
	}
	divide_and_conquer(arr, 0, 0, n);
}