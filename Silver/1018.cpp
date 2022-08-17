#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

int minOneLayer(int n, int m) {
	int startBlackCount = 0; // 짝수항이 B일 때 교체 비용
	int startWhiteCount = 0; // 짝수항이 W일 때 교체 비용

	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if ((i + j) % 2 == 0) { // 짝수항 
				if (board[i][j] == 'W')
					startBlackCount++; // 짝수항이 W면 교체비용 발생
				else if (board[i][j] == 'B')
					startWhiteCount++; // 짝수항이 B면 교체비용 발생
			}
			else { // 홀수항
				if (board[i][j] == 'W')
					startWhiteCount++; // 홀수항이 W면 교체비용 발생
				else if (board[i][j] == 'B')
					startBlackCount++; // 홀수항이 B면 교체비용 발생
			}
		}
	}

	if (startWhiteCount < startBlackCount)
		return startWhiteCount;
	else
		return startBlackCount;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<char> line;
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			line.push_back(c);
		}
		board.push_back(line);
	}

	int count = 64;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int mol = minOneLayer(i, j);
			if (count > mol)
				count = mol;
		}
	}

	cout << count << endl;
}