#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double result1 = a / c + b / d;
    double result2 = c / d + a / b;
    double result3 = d / b + c / a;
    double result4 = b / a + d / c;

    double maxVal = result1;
    int maxRotate = 0;
    if (maxVal < result2) {
        maxVal = result2;
        maxRotate = 1;
    }
    if (maxVal < result3) {
        maxVal = result3;
        maxRotate = 2;
    }
    if (maxVal < result4) {
        maxVal = result4;
        maxRotate = 3;
    }
    cout << maxRotate;
}