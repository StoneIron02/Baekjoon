#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l, r;
    cin >> l >> r;
    if (l == r && l == 0) {
        cout << "Not a moose";
        return 0;
    }
    if (l == r) {
        cout << "Even " << (l * 2);
    } else if (l > r) {
        cout << "Odd " << (l * 2);
    } else {
        cout << "Odd " << (r * 2);
    }
}