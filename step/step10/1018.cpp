#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

int minOneLayer(int n, int m) {
	int startBlackCount = 0; // ¦������ B�� �� ��ü ���
	int startWhiteCount = 0; // ¦������ W�� �� ��ü ���

	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if ((i + j) % 2 == 0) { // ¦���� 
				if (board[i][j] == 'W')
					startBlackCount++; // ¦������ W�� ��ü��� �߻�
				else if (board[i][j] == 'B')
					startWhiteCount++; // ¦������ B�� ��ü��� �߻�
			}
			else { // Ȧ����
				if (board[i][j] == 'W')
					startWhiteCount++; // Ȧ������ W�� ��ü��� �߻�
				else if (board[i][j] == 'B')
					startBlackCount++; // Ȧ������ B�� ��ü��� �߻�
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