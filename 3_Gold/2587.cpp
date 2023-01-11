#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		sum += num;
	}
	sort(arr, arr + 5);
	cout << (sum / 5) << "\n";
	cout << arr[2] << "\n";
}