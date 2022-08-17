#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int num;
	cin >> num;

	int* aArr = new int[num];
	int* bArr = new int[num];

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		aArr[i] = a;
		bArr[i] = b;
	}
	for (int i = 0; i < num; i++) {
		cout << "Case #" << i + 1 << ": " << aArr[i] << " + " << bArr[i] << " = " << aArr[i] + bArr[i] << "\n";
	}
}