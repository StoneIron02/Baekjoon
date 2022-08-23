#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589793;

int main() {
	double r;
	cin >> r;
	cout << fixed << setprecision(6) << (r * r * PI) << "\n";
	cout << fixed << setprecision(6) << (r * r * 2) << "\n";
}