// 에라토스테네스의 체
#include <iostream>
using namespace std;

#define ISITEM true;
#define NOITEM false;

void eratos(int n, int k) {
	if (n < 2) return;
	bool* arr = new bool[n + 1];
	for (int i = 2; i <= n; i++)
		arr[i] = ISITEM;

	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			for (int j = i; j <= n; j += i) {
				if (arr[j]) {
					count++;
					if (count == k) {
						cout << j << endl;
						return;
					}
				}
				arr[j] = NOITEM;
			}
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	eratos(n, k);
}


/*

void eratos(int n) {
	if (n < 2) return;
	bool* arr = new bool[n + 1];
	for (int i = 2; i <= n; i++)
		arr[i] = ISITEM;

	for (int i = 2; i * i <= n; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= n; j += i) { // i 이전의 모든 수들은 이미 소수를 제외하고 배수들이 다 지워져있으므로 어차피 NOITEM 상태이므로, i * i부터 시작
				arr[j] = NOITEM;
			}
		}
	}
}

*/