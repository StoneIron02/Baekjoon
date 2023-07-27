#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a1, a0;
    cin >> a1 >> a0;
    int c, n0;
    cin >> c >> n0;
    bool flag = true;
    for (int n = n0; n <= 100; n++) {
        int f = a1 * n + a0;
        int cg = c * n;
        if (f > cg)
            flag = false;
    }
    if (flag)
        cout << 1;
    else
        cout << 0;
}