#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int max = 0;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		cnt -= num;
		cin >> num;
		cnt += num;
		max = cnt > max ? cnt : max;
	}
	cout << max;
}