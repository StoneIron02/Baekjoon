#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	int sum = 0;
	sum += t / 5;
	t %= 5;
	sum += t / 4;
	t %= 4;
	sum += t / 3;
	t %= 3;
	sum += t / 2;
	t %= 2;
	sum += t / 1;
	t %= 1;
	cout << sum;
}