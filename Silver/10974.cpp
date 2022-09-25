#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int* num = new int[n];
	for (int i = 1; i <= n; i++) {
		num[i - 1] = i;
	}

	do {
		for (int i = 1; i <= n; i++) {
			cout << num[i - 1] << " ";
		}
		cout << "\n";
	} while (next_permutation(num, num + n));
}