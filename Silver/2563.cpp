#include <iostream>
using namespace std;

bool arr[100][100]{ 0 };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[w + j][h + k] = 1;
			}
		}
	}
	int cnt = 0;
	for (int j = 0; j < 100; j++) {
		for (int k = 0; k < 100; k++) {
			if (arr[j][k])
				cnt++;
		}
	}
	cout << cnt;
}