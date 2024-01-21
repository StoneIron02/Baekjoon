#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        int diff = c - a;
        if (diff % b != 0 || diff / b < 0) {
            cout << "X\n";
        } else {
            cout << (diff / b + 1) << "\n";
        }
    }
}