#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a;
	cin >> b;
	int b1 = b % 10;
	int b2 = (b / 10) % 10;
	int b3 = ((b / 10) / 10) % 10;

	cout << a * b1 << endl;
	cout << a * b2 << endl;
	cout << a * b3 << endl;
	cout << a * b << endl;
}