#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cout << "Class " << i << "\n";
		int n;
		cin >> n;
		vector<int> score(n);
		for (int j = 0; j < n; j++)
			cin >> score[j];

		sort(score.begin(), score.end());
		int gap = 0;
		for (int j = 1; j < n; j++) {
			int curGap = abs(score[j - 1] - score[j]);
			if (gap < curGap)
				gap = curGap;
		}

		cout << "Max " << score[n - 1] << ", ";
		cout << "Min " << score[0] << ", ";
		cout << "Largest gap " << gap << "\n";
	}
}