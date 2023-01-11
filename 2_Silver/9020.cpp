#include <iostream>
using namespace std;

#define ISITEM true;
#define NOITEM false;

void eratos(int n) {
	bool* arr = new bool[n + 1];
	for (int i = 2; i <= n; i++)
		arr[i] = ISITEM;

	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			for (int j = i * 2; j <= n; j += i) {
				arr[j] = NOITEM;
			}
		}
	}

	for (int i = n / 2; i <= n; i++) {
		if (arr[n - i] && arr[i]) {
			cout << n - i << " " << i << "\n";
			return;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		eratos(n);
	}
}