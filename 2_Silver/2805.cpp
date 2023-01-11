#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxHeight = 0;

void bs(vector<int> v, int m, int start, int end) {
	if (start > end)
		return;
	int mid = (start + end) / 2;
	long long sum = 0;
	for (int h : v) {
		if (h > mid)
			sum += ((long long)h - mid);
	}
	if (sum >= m) {
		maxHeight = (maxHeight < mid ? mid : maxHeight);
		bs(v, m, mid + 1, end);
	}
	else {
		bs(v, m, start, mid - 1);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	bs(v, m, 0, v[n - 1]);
	cout << maxHeight;
}