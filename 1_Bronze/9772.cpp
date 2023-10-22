#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        double x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            cout << "AXIS\n";
            break;
        }

        if (x == 0 || y == 0) {
            cout << "AXIS\n";
            continue;
        }

        if (x > 0 && y > 0) {
            cout << "Q1\n";
        } else if (x < 0 && y > 0) {
            cout << "Q2\n";
        } else if (x < 0 && y < 0) {
            cout << "Q3\n";
        } else if (x > 0 && y < 0) {
            cout << "Q4\n";
        }
    }
}