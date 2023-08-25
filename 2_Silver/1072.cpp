#include <iostream>

using namespace std;

long long x, y, z_origin;

void binarySearch(long long left, long long right) {
    if (left == right) {
        long long z = 100 * (y + left) / (x + left);
        if (z != z_origin) {
            cout << left;
        } else {
            cout << -1;
        }
        return;
    }

    long long cnt = (left + right) / 2;

    long long z = 100 * (y + cnt) / (x + cnt);
    if (z != z_origin) {
        binarySearch(left, cnt);
    } else {
        binarySearch(cnt + 1, right);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> x >> y;

    z_origin = 100 * y / x;
    binarySearch(1, 1'000'000'000);
}