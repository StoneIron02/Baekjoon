#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<int> crains(n);
	for (int i = 0; i < n; i++)
		cin >> crains[i];
	sort(crains.begin(), crains.end());

	int m;
	cin >> m;
	vector<int> boxes(m);
	for (int i = 0; i < m; i++)
		cin >> boxes[i];
	sort(boxes.begin(), boxes.end());

	if (crains.back() < boxes.back()) {
		cout << -1;
		exit(0);
	}

	int min = 0;
	while (!boxes.empty()) {
		min++;
		for (int i = 0; i < n; i++) {
			int crain = crains[i];
			int boxIndex = upper_bound(boxes.begin(), boxes.end(), crain) - boxes.begin() - 1;
			if (boxIndex == -1) continue;
			boxes.erase(boxes.begin() + boxIndex);
			if (boxes.empty()) break;
		}
	}
	cout << min;
}