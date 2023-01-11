#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	bool attend[31] = {0};
	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		attend[num] = true;
	}
	for (int i = 1; i <= 30; i++) {
		if (!attend[i])
			cout << i << "\n";
	}
}