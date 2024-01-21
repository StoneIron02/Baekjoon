#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double d1, d2;
    cin >> d1 >> d2;

    double result = 2 * 3.141592 * d2 + d1 * 2;
    cout << fixed << setprecision(10) << result;
}