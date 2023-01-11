#include <iostream>
using namespace std;

int cnt[10]{ 0 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	while (n > 0) {
		int cur = n % 10;
		if (cur == 6 || cur == 9) {
			if (cnt[6] < cnt[9])
				cnt[6]++;
			else
				cnt[9]++;
		}
		else {
			cnt[cur]++;
		}
		n /= 10;
	}
	int max = cnt[0];
	for (int i = 1; i < 10; i++)
		max = cnt[i] > max ? cnt[i] : max;
	cout << max;
}