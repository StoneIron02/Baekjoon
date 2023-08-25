#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l, d;
    cin >> n >> l >> d;
    int sec = 0;
    while (sec < (l + 5) * n) {
        sec += l;
        for (int i = 0; i < 5; i++, sec++) {
            if (sec % d == 0) {
                cout << sec;
                return 0;
            }
        }
    }
    while (true) {
        if (sec % d == 0) {
            cout << sec;
            return 0;
        }
        sec++;
    }
}