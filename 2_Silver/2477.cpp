#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct pos {
	int x, y;
	pos(int x, int y) : x(x), y(y) {
	}
	bool isXMid(int x, int y) {
		return (this->x == x && this->y != y);
	}
	bool isYMid(int x, int y) {
		return (this->x != x && this->y == y);
	}
};

int main() {
	int n;
	cin >> n;
	vector<pos*> positions;
	priority_queue<int> xs;
	priority_queue<int> ys;
	int curX = 0, curY = 0;

	for (int i = 0; i < 6; i++) {
		int dir, val;
		cin >> dir >> val;
		if (dir == 1)
			curX += val;
		if (dir == 2)
			curX -= val;
		if (dir == 3)
			curY -= val;
		if (dir == 4)
			curY += val;

		xs.push(curX);
		ys.push(curY);
		pos* p = new pos(curX, curY);
		positions.push_back(p);
	}

	int maxX = xs.top();
	xs.pop(); xs.pop();
	int midX = xs.top();
	xs.pop(); xs.pop();
	int minX = xs.top();
	xs.pop(); xs.pop();

	int maxY = ys.top();
	ys.pop(); ys.pop();
	int midY = ys.top();
	ys.pop(); ys.pop();
	int minY = ys.top();
	ys.pop(); ys.pop();

	pos *midXpos = NULL, *midYpos = NULL;
	for (int i = 0; i < positions.size(); i++) {
		if (positions[i]->isXMid(midX, midY)) {
			midXpos = positions[i];
		}
		if (positions[i]->isYMid(midX, midY)) {
			midYpos = positions[i];
		}
	}
	int smallS = abs(midXpos->y - midY) * abs(midYpos->x - midX);
	int largeS = (maxY - minY) * (maxX - minX);
	cout << n * (largeS - smallS);
}