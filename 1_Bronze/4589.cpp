#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << "Gnomes:\n";
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool greater = false, less = false;
        if (a <= b && b <= c) {
            less = true;
        }
        if (a >= b && b >= c) {
            greater = true;
        }
        if (less || greater) {
            cout << "Ordered\n";
        } else {
            cout << "Unordered\n";
        }
    }
}