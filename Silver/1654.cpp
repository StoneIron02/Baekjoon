#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNum = 0;

void binary_search(vector<int>& vector, int n, unsigned int start, unsigned int end) {
	if (start > end)
		return;

	int mid = (start + end) / 2;
	int sum = 0;
	for (int num : vector) {
		sum += num / mid;
	}

	if (sum >= n) {
		maxNum = mid;
		binary_search(vector, n, mid + 1, end);
	}
	else {
		binary_search(vector, n, start, mid - 1);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int k, n;
	cin >> k >> n;
	vector<int> vector(k);
	for (int i = 0; i < k; i++)
		cin >> vector[i];
	sort(vector.begin(), vector.end());
	binary_search(vector, n, 1, vector[k - 1]);
	cout << maxNum;
}