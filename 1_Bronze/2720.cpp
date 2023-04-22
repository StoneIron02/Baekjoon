#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;

        cout << (c / 25) << " ";
        c %= 25;
        cout << (c / 10) << " ";
        c %= 10;
        cout << (c / 5) << " ";
        c %= 5;
        cout << c << "\n";
    }
}