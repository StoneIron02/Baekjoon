#include <iostream>
using namespace std;

#define ISITEM true;
#define NOITEM false;

void eratos(int n) {
	bool* arr = new bool[n * 2 + 1];
	for (int i = 2; i <= n * 2; i++)
		arr[i] = ISITEM;

	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			for (int j = i; j <= n * 2; j += i) {
				arr[j] = NOITEM;
			}
		}
	}
	int count = 0;
	for (int i = n + 1; i <= n * 2; i++) {
		if (arr[i]) {
			count++;
			for (int j = i; j <= n * 2; j += i) {
				arr[j] = NOITEM;
			}
		}
	}
	cout << count << "\n";
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;
		eratos(n);
	}
}