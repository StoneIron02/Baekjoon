#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int w = 0;
	while (w < 1667) {
		for (int i = 0; i <= w; i++) {
			int num = (3 * i + 5 * (w - i));
			if (num == n) {
				cout << w << endl;
				return 0;
			}
		}
		w++;
	}
	cout << -1 << endl;
}

/*

vector<vector<int>> table;
	for (int i = 0; i <= 5000 / 8 + 1; i++) {
		table.push_back(vector<int>());
		for (int j = 0; j <= 5000 / 8 + 1; j++) {
			table[i].push_back(3 * i + 5 * j);
		}
	}

	for (int i = 0; i <= 5000 / 8 + 1; i++) {
		for (int j = 0; j <= 5000 / 8 + 1; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

for (int i = 0; i <= 5000 / 8 + 1; i++) {
	for (int j = 0; j <= 5000 / 8 + 1; j++) {
		if (table[i][j] == n) {
			cout << i + j << endl;
			return 0;
		}
	}
}
cout << -1 << endl;

*/