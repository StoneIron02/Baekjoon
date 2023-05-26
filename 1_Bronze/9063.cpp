#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int minX = INT32_MAX, maxX = INT32_MIN, minY = INT32_MAX, maxY = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (minX > x)
            minX = x;
        if (maxX < x)
            maxX = x;
        if (minY > y)
            minY = y;
        if (maxY < y)
            maxY = y;
    }

    cout << ((maxX - minX) * (maxY - minY));
}