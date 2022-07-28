#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	int result = a * b * c;

	int count[10] = { 0 };

	while (!(result / 10 == 0 && result % 10 == 0)) {
		int n = result % 10;
		count[n]++;
		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << count[i] << "\n";
	}

}