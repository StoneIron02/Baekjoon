#include <iostream>
using namespace std;

#define ISITEM true;
#define NOITEM false;

void eratos(int m, int n) {
	if (n < 2) return;
	bool* arr = new bool[n + 1];
	for (int i = 2; i <= n; i++)
		arr[i] = ISITEM;

	for (int i = 2; i < m; i++) {
		if (arr[i]) {
			for (int j = i; j <= n; j += i) {
				arr[j] = NOITEM;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (arr[i]) {
			cout << i << "\n";
			for (int j = i; j <= n; j += i) {
				arr[j] = NOITEM;
			}
		}
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	eratos(m, n);
}