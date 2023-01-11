#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int l, p;
	cin >> l >> p;

	int people = l * p;

	int arr[5];
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		arr[i] = num - people;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
}