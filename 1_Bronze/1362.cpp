#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int tr = 1;
    while (true) {
        int o, w;
        cin >> o >> w;
        if (o == 0 && w == 0) break;
        bool isDead = false;

        while (true) {
            char c;
            int n;
            cin >> c >> n;
            if (c == '#' && n == 0) break;

            if (!isDead) {
                if (c == 'E') {
                    w -= n;
                } else {
                    w += n;
                }
            }

            if (w <= 0) {
                isDead = true;
            }
        }
        if (w <= 0) {
            cout << tr << " RIP\n";
        }
        else if (w > 0.5 * o && w < 2 * o) {
            cout << tr << " :-)\n";
        }
        else {
            cout << tr << " :-(\n";
        }
        tr++;
    }
}