#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int add = c - b;
	if (add <= 0) {
		cout << -1 << endl;
		return 0;
	}
	
	int count = a / add + 1;
	cout << count << endl;
}