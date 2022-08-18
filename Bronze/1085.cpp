#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int up = abs(h - y);
	int down = abs(0 - y);
	int left = abs(w - x);
	int right = abs(0 - x);

	int min = up;
	min > down ? min = down : min = min;
	min > left ? min = left : min = min;
	min > right ? min = right : min = min;
	cout << min;
}