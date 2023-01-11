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
		return (getDistance(center, p) <= r);
	}
};

struct rectangle {
	pos* leftbottom;
	pos* righttop;
	rectangle(pos* leftbottom, pos* righttop) : leftbottom(leftbottom), righttop(righttop) {
	}
	bool isInRectangle(pos* p) {
		return ((leftbottom->x <= p->x && righttop->x >= p->x) && (leftbottom->y <= p->y && righttop->y >= p->y));
	}
};

int main() {
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;
	int r = h / 2;
	circle* lCircle = new circle(new pos(x, y + r), r);
	circle* rCircle = new circle(new pos(x + w, y + r), r);
	rectangle* rect = new rectangle(new pos(x, y), new pos(x + w, y + h));
	int count = 0;
	for (int i = 0; i < p; i++) {
		int px, py;
		cin >> px >> py;
		pos* pp = new pos(px, py);
		if (lCircle->isInCircle(pp) || rCircle->isInCircle(pp) || rect->isInRectangle(pp)) {
			count++;
		}
	}
	cout << count << "\n";
}