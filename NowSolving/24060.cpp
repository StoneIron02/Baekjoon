#include <iostream>
using namespace std;

void merge(int* arr, int p, int q, int r) {
	int i = p, j = q + 1, t = 0;
	int* tmp = new int[r + 1];
	while (i <= q && j <= r) {
		if (arr[i] <= arr[j])
			tmp[t++] = arr[i++];
		else
			tmp[t++] = arr[j++];
	}
	while (i <= q)
		tmp[t++] = arr[i++];
	while (j <= r)
		tmp[t++] = arr[j++];
	i = p, t = 0;
	while (i <= r)
		arr[i++] = tmp[t++];
}

void merge_sort(int* arr, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	merge_sort(arr, 0, n - 1);
	cout << arr[k];
}