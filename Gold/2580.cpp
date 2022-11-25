#include <iostream>
#include <vector>
using namespace std;

int arr[9][9]{ 0 };
vector<pair<int, int>> toFind;

bool isValid(int r, int c, int i) {
	int blockR = r / 3;
	int blockC = c / 3;
	for (int cr = 0; cr < 9; cr++) {
		if (cr != r && arr[cr][c] == i)
			return false;
	}
	for (int cc = 0; cc < 9; cc++) {
		if (cc != c && arr[r][cc] == i)
			return false;
	}
	for (int cr = blockR * 3; cr < (blockR + 1) * 3; cr++) {
		for (int cc = blockC * 3; cc < (blockC + 1) * 3; cc++) {
			if (cr != r && cc != c && arr[cr][cc] == i)
				return false;
		}
	}
	return true;
}

void backTracking(int index) {
	if (index == toFind.size()) {
		for (int r = 0; r < 9; r++) {
			for (int c = 0; c < 9; c++) {
				cout << arr[r][c] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	int r = toFind[index].first;
	int c = toFind[index].second;
	for (int i = 1; i <= 9; i++) {
		if (isValid(r, c, i)) {
			arr[r][c] = i;
			backTracking(index + 1);
		}
	}
	arr[r][c] = 0;
	return;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	for (int r = 0; r < 9; r++) {
		for (int c = 0; c < 9; c++) {
			int num;
			cin >> num;
			arr[r][c] = num;
			if (num == 0)
				toFind.push_back({ r, c });
		}
	}
	backTracking(0);
}