#include <iostream>
#include <algorithm>
using namespace std;

int arr[2'000'000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int i;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = n; i < n + m; i++)
		cin >> arr[i];
	sort(arr, arr + n + m);
	for (i = 0; i < n + m; i++)
		cout << arr[i] << " ";
}