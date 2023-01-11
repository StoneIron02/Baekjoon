#include <iostream>
using namespace std;

int n;
int cnt = 0;
bool row[16][15]{ 0 };
bool col[16][15]{ 0 };
bool diagup[16][7]{ 0 }; // r+c=index
bool diagdown[16][7]{ 0 }; // r-c+3=index

void backtracking(int cur, int iBack, int jBack) {
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = iBack; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i <= iBack && j < jBack) continue;
			if (row[cur][i]) continue;
			if (col[cur][j]) continue;
			if (diagup[cur][i + j]) continue;
			if (diagdown[cur][i - j + 3]) continue;

			for (int idx = 0; idx < 15; idx++) {
				row[cur + 1][idx] = row[cur][idx];
				col[cur + 1][idx] = col[cur][idx];
			}
			for (int idx = 0; idx < 7; idx++) {
				diagup[cur + 1][idx] = diagup[cur][idx];
				diagdown[cur + 1][idx] = diagdown[cur][idx];
			}
			row[cur + 1][i] = 1;
			col[cur + 1][j] = 1;
			diagup[cur + 1][i + j] = 1;
			diagdown[cur + 1][i - j + 3] = 1;
			backtracking(cur + 1, i, j);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	backtracking(0, 0, 0);
	cout << cnt;
}