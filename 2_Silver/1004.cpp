#include <iostream>
#include <cmath>
using namespace std;

struct pos {
	int x, y;
	pos(int x, int y) : x(x), y(y) {
	}
};

double getDistance(pos* p1, pos* p2) {
	return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

struct circle {
	pos* center;
	int r;
	circle(pos* center, int r) : center(center), r(r) {
	}
	bool isInCircle(pos* p) {
		return (getDistance(center, p) < r);
	}
};

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		pos* p1 = new pos(x1, y1);
		pos* p2 = new pos(x2, y2);
		int n;
		cin >> n;
		int count = 0;
		for (int j = 0; j < n; j++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			circle* c = new circle(new pos(cx, cy), r);
			if (c->isInCircle(p1) != c->isInCircle(p2))
				count++;
		}

		cout << count << "\n";
	}
}