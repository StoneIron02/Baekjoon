#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int m, f;
        cin >> m >> f;
        if (m == 0 && f == 0)
            break;
        cout << (m + f) << "\n";
    }
}