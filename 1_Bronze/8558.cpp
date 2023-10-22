#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 0 || n == 1) {
        cout << 1;
        return 0;
    }
    int cur = 1;
    for (int i = 2; i <= n; i++) {
        cur = (cur * i) % 10;
    }
    cout << cur;
}