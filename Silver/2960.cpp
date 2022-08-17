// �����佺�׳׽��� ü
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
			for (int j = i * i; j <= n; j += i) { // i ������ ��� ������ �̹� �Ҽ��� �����ϰ� ������� �� �����������Ƿ� ������ NOITEM �����̹Ƿ�, i * i���� ����
				arr[j] = NOITEM;
			}
		}
	}
}

*/