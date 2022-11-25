#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	pair<int, int> maxPoint = { -1, -1 };
	int max = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int num;
			cin >> num;
			if (num > max) {
				maxPoint = pair<int, int>{ i, j };
				max = num;
			}
		}
	}
	cout << max << "\n";
	cout << maxPoint.first + 1 << " " << maxPoint.second + 1;
}