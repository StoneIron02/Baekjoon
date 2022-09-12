#include <iostream>
using namespace std;

int cnt[2] = {0};

void divide_and_conquer(int** arr, int startI, int startJ, int n) {
	int num = arr[startI][startJ];
	if (n == 1) {
		cnt[num]++;
		return;
	}
	for (int i = startI; i < startI + n; i++) {
		for (int j = startJ; j < startJ + n; j++) {
			if (num != arr[i][j]) {
				for (int newI = startI; newI < startI + n; newI += n / 2) {
					for (int newJ = startJ; newJ < startJ + n; newJ += n / 2) {
						divide_and_conquer(arr, newI, newJ, n / 2);
					}
				}
				return;
			}
		}
	}
	cnt[num]++;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	divide_and_conquer(arr, 0, 0, n);
	cout << cnt[0] << "\n" << cnt[1];
}