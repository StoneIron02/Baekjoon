#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int a = 300, b = 60, c = 10;
	int t;
	cin >> t;
	int aCount = t / a;
	t %= a;
	int bCount = t / b;
	t %= b;
	int cCount = t / c;
	t %= c;
	if (t != 0)
		cout << -1;
	else
		cout << aCount << " " << bCount << " " << cCount;
}