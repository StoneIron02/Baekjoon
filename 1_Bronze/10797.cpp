#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		if (n == num)
			cnt++;
	}

	cout << cnt;
}