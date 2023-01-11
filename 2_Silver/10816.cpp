#include <iostream>
using namespace std;

int arr[20000001] = { 0 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[num + 10000000]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << arr[num + 10000000] << " ";
	}
}