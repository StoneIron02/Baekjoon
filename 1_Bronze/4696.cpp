#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        double n;
        cin >> n;
        if (n == 0) break;
        double result = 1 + n + n * n + n * n * n + n * n * n * n;
        cout << fixed << setprecision(2) << result << "\n";
    }
}