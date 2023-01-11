#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	cout << (k / m) << " ";
	k %= m;
	cout << k;
}