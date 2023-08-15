#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    double r1 = 1.0 * a * b / c;
    double r2 = 1.0 * a / b * c;
    cout << (int)(max(r1, r2));
}