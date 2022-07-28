#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int num;
	cin >> num;

	int* out = new int[num];

	for (int i = 0; i < num; i++) {
		int a, b;
		cin >> a >> b;
		out[i] = a + b;
	}
	for (int i = 0; i < num; i++) {
		cout << out[i] << "\n";
	}
}