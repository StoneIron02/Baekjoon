#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	cin >> a >> b >> v;

	int q = (v - a) / (a - b);
	int r = (v - a) % (a - b);
	if (r == 0)
		cout << q + 1 << endl;
	else
		cout << q + 2 << endl;
}