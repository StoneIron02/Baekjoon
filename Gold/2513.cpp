#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, s;
vector<pair<int, int>> posLefts;
vector<pair<int, int>> posRights;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		int pos, students;
		cin >> pos >> students;
		if (pos < s) {
			int distance = s - pos;
			posLefts.push_back({ distance , students });
		}
		else {
			int distance = pos - s;
			posRights.push_back({ distance , students });
		}
	}
	sort(posLefts.begin(), posLefts.end(), greater<pair<int, int>>());
	sort(posRights.begin(), posRights.end(), greater<pair<int, int>>());
	int sumDistance = 0;
	int leftIndex = 0;
	while (leftIndex < posLefts.size()) {
		sumDistance += posLefts[leftIndex].first * 2;
		int i = 0;
		while (i < k && leftIndex < posLefts.size()) {
			i++;
			if (--posLefts[leftIndex].second == 0)
				leftIndex++;
		}
	}
	int rightIndex = 0;
	while (rightIndex < posRights.size()) {
		sumDistance += posRights[rightIndex].first * 2;
		int i = 0;
		while (i < k && rightIndex < posRights.size()) {
			i++;
			if (--posRights[rightIndex].second == 0)
				rightIndex++;
		}
	}
	cout << sumDistance;
}