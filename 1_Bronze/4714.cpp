#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double x, y;
    while (true) {
        cin >> x;
        if (x < 0) {
            break;
        }

        y = x * 0.167;
        cout << "Objects weighing " << fixed << setprecision(2) << x << " on Earth will weigh " << y << " on the moon.\n";
    }
}