#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double n;
    cin >> n;
    cout << fixed << setprecision(2) << (n / 4);
}