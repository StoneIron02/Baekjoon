#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int W, n;
		cin >> W >> n;
		int x[1000];
		int w[1000];
		for (int j = 0; j < n; j++) {
			cin >> x[j] >> w[j];
		}
		int curW = 0;
		int s = 0;
		for (int j = 0; j < n; j++) {
			if (curW + w[j] > W) {
				s += 2 * x[j];
				curW = 0;
			}
			curW += w[j];
			if (curW == W && j < n - 1) {
				s += 2 * x[j];
				curW = 0;
			}
		}
		s += 2 * x[n - 1];
		cout << s << "\n";
	}
}