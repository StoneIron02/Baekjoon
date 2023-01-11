#include <iostream>
#include <vector>
using namespace std;

int greedy(vector<pair<int, int>>& arr) {
	int sum = arr[0].second;
	for (int i = 1; i < arr.size(); i++) {
		int remain = arr[i].second - arr[i - 1].first;
		int add;
		if (remain < 0) {
			add = 0;
			if (i < arr.size() - 1)
				arr[i + 1].second += remain;
		}
		else
			add = remain;
		sum += add;
	}
	return sum;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}
	cout << greedy(arr);
}