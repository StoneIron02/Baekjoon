#include <iostream>
using namespace std;

void hanoi(int n, int source, int destination, int tmp) {
	if (n == 0) return;
	hanoi(n - 1, source, tmp, destination);
	cout << source << " " << destination << "\n";
	hanoi(n - 1, tmp, destination, source);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int cnt = 1;
	for (int i = 0; i < n; i++)
		cnt *= 2;
	cnt -= 1;
	cout << cnt << "\n";
	hanoi(n, 1, 3, 2);
}