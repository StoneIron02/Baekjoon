#include <iostream>
using namespace std;

void devide(int num) {
	if (num == 1) return;
	for (int i = 2; i < 10000000; i++) {
		if (num % i == 0) {
			cout << i << endl;
			return devide(num / i);
		}
	}
}

int main() {
	int n;
	cin >> n;

	devide(n);
}