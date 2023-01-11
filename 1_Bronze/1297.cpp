#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	double d, h, w;
	cin >> d >> h >> w;
	double k = sqrt(pow(d, 2) / (pow(h, 2) + pow(w, 2)));
	int kh = k * h;
	int kw = k * w;
	cout << kh << " " << kw;
}