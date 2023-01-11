#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int* out = new int[num];

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		out[i] = a + b;
	}
	for (int i = 0; i < num; i++) {
		cout << out[i] << endl;
	}
}