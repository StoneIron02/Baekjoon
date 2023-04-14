#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            k--;
            if (k == 0) {
                cout << i;
                exit(0);
            }
        }
    }

    if (k != 0)
        cout << 0;

}