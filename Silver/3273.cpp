#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int>& arr, int x) {
	sort(arr.begin(), arr.end());
	int i = 0, j = arr.size() - 1;
	int count = 0;
	while (i < j) {
		int findNum = x - arr[i];
		while (j > 0 && arr[j] > findNum)
			j -= 1;
		if (arr[j] == findNum && i < j)
			count++;
		i++;
	}
	return count;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int x;
	cin >> x;
	cout << find(arr, x);
}