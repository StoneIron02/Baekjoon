#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double A;
    cin >> A;
    double l = sqrt(A);
    cout << fixed << setprecision(10) << (l * 4);
}