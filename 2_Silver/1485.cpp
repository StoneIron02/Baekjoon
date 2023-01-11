#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<pair<int, int>> arr;
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			arr.push_back({ a, b });
		}

		vector<int> lengthPow;
		for (int a = 0; a < 4; a++) {
			for (int b = a + 1; b < 4; b++) {
				int lpow = pow(arr[b].first - arr[a].first, 2) + pow(arr[b].second - arr[a].second, 2);
				lengthPow.push_back(lpow);
			}
		}
		sort(lengthPow.begin(), lengthPow.end());

		bool flag = 1;
		if (lengthPow[0] != lengthPow[1])
			flag = 0;
		if (lengthPow[0] != lengthPow[2])
			flag = 0;
		if (lengthPow[0] != lengthPow[3])
			flag = 0;
		if (lengthPow[4] != lengthPow[5])
			flag = 0;
		cout << flag << "\n";
	}
}