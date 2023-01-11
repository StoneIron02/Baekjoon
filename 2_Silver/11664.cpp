#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

double ternary_search(double Ax, double Ay, double Az, double Bx, double By, double Bz, double Cx, double Cy, double Cz) {
	if (distance(Ax, Ay, Az, Bx, By, Bz) < 1e-6) {
		return distance(Ax, Ay, Az, Cx, Cy, Cz);
	}
	// 삼등분점 구하기
	double Px = (1 * Bx + 2 * Ax) / 3;
	double Py = (1 * By + 2 * Ay) / 3;
	double Pz = (1 * Bz + 2 * Az) / 3;
	double Qx = (2 * Bx + 1 * Ax) / 3;
	double Qy = (2 * By + 1 * Ay) / 3;
	double Qz = (2 * Bz + 1 * Az) / 3;
	// P에 대한 거리가 Q에 대한 거리보다 클 경우 최솟값은 Q와 가까운 곳에 있음 => 범위를 P 이후로 좁힘
	if (distance(Px, Py, Pz, Cx, Cy, Cz) > distance(Qx, Qy, Qz, Cx, Cy, Cz))
		return ternary_search(Px, Py, Pz, Bx, By, Bz, Cx, Cy, Cz);
	else // Q에 대한 거리가 P에 대한 거리보다 클 경우 최솟값은 P와 가까운 곳에 있음 => 범위를 Q 이전으로 좁힘
		return ternary_search(Ax, Ay, Az, Qx, Qy, Qz, Cx, Cy, Cz);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz;
	cin >> Ax >> Ay >> Az >> Bx >> By >> Bz >> Cx >> Cy >> Cz;
	cout << fixed << setprecision(10) << ternary_search(Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz);
}