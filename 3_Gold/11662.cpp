#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double ternary_search(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy) {
	if (distance(Ax, Ay, Bx, By) < 1e-9 || distance(Cx, Cy, Dx, Dy) < 1e-9) {
		return distance(Ax, Ay, Cx, Cy);
	}

	// 삼등분점 구하기
	double Px = (1 * Bx + 2 * Ax) / 3;
	double Py = (1 * By + 2 * Ay) / 3;
	double Qx = (2 * Bx + 1 * Ax) / 3;
	double Qy = (2 * By + 1 * Ay) / 3;
	double Rx = (1 * Dx + 2 * Cx) / 3;
	double Ry = (1 * Dy + 2 * Cy) / 3;
	double Sx = (2 * Dx + 1 * Cx) / 3;
	double Sy = (2 * Dy + 1 * Cy) / 3;
	// 범위 좁혀나가기
	if (distance(Px, Py, Rx, Ry) > distance(Qx, Qy, Sx, Sy))
		return ternary_search(Px, Py, Bx, By, Rx, Ry, Dx, Dy);
	else
		return ternary_search(Ax, Ay, Qx, Qy, Cx, Cy, Sx, Sy);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
	cout << fixed << setprecision(10) << ternary_search(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy);
}