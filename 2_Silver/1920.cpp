#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
int binary_search(T* arr, T key, int low, int high) {
	if (high < low)
		return -1;

	int mid = (low + high) / 2;
	if (arr[mid] == key)
		return mid;
	else if (arr[mid] < key)
		return binary_search(arr, key, mid + 1, high);
	else
		return binary_search(arr, key, low, mid - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (binary_search(arr, num, 0, n - 1) != -1)
			cout << "1\n";
		else
			cout << "0\n";
	}
}