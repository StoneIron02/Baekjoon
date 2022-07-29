#include <iostream>
using namespace std;

int n, m, k;
int now_size = 0, max_size = 0;
int** trashMap;

void printScreen() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (trashMap[i][j] == 1)
				cout << '#';
			else
				cout << '.';
		}
		cout << "\n";
	}
	cout << "\n";
}

void find(int r, int c, int vec_x, int vec_y) {
	//printScreen();
	if (trashMap[r - 1][c - 1] == 1) {
		now_size++;
		trashMap[r - 1][c - 1] = 0;
		if (r > 1 && !(vec_x == 0 && vec_y == 1)) { // up
			find(r - 1, c, 0, -1);
		}
		if (r < n && !(vec_x == 0 && vec_y == -1)) { // down
			find(r + 1, c, 0, 1);
		}
		if (c > 1 && !(vec_x == 1 && vec_y == 0)) { // left
			find(r, c - 1, -1, 0);
		}
		if (c < m && !(vec_x == -1 && vec_y == 0)) { // right
			find(r, c + 1, 1, 0);
		}
		if (vec_x == 0 && vec_y == 0) {
			max_size < now_size ? max_size = now_size : max_size = max_size;
			now_size = 0;
		}
	}
	else {
		return;
	}
}


int main() {
	cin >> n >> m >> k;

	trashMap = new int* [n];
	for (int i = 0; i < n; i++) {
		trashMap[i] = new int[m];
		for (int j = 0; j < m; j++) {
			trashMap[i][j] = 0;
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		trashMap[r - 1][c - 1] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			find(i, j, 0, 0);
		}
	}

	cout << max_size;
}