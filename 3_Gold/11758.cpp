#include <iostream>
#include <cmath>
using namespace std;

int cross(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int p[3][2];
	for (int i = 0; i < 3; i++) {
		cin >> p[i][0];
		cin >> p[i][1];
	}
	int crossVal = cross(p[1][0] - p[0][0], p[1][1] - p[0][1], p[2][0] - p[0][0], p[2][1] - p[0][1]);
	if (crossVal == 0)
		cout << crossVal;
	else
		cout << crossVal / abs(crossVal);
}