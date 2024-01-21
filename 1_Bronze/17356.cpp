#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    double m = 1.0 * (b - a) / 400;
    double result = 1 / (1 + pow(10, m));
    cout << fixed << setprecision(20) << result;
}