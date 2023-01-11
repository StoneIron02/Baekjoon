#include <iostream>
using namespace std;

int arr[10001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i < 10001; i++) {
		while (arr[i] > 0) {
			cout << i << "\n";
			arr[i]--;
		}
	}
}