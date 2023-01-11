#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int v;
	cin >> v;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == v)
			count++;
	}
	cout << count;
}