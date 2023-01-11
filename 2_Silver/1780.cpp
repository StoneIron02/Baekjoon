#include <iostream>s
using namespace std;

int count_num[3];

void check(int** arr, int startI, int startJ, int n) {
	int num = arr[startI][startJ];
	if (n == 1) {
		count_num[num + 1]++;
		return;
	}
	bool correct = true;
	for (int i = startI; i < startI + n; i++) {
		for (int j = startJ; j < startJ + n; j++) {
			if (arr[i][j] != num) {
				correct = false;
			}
		}
	}
	if (correct) {
		count_num[num + 1]++;
		return;
	}
	else {
		for (int i = startI; i < startI + n; i += n / 3) {
			for (int j = startJ; j < startJ + n; j += n / 3) {
				check(arr, i, j, n / 3);
			}
		}
		
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	check(arr, 0, 0, n);
	cout << count_num[0] << "\n";
	cout << count_num[1] << "\n";
	cout << count_num[2] << "\n";
}