#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long x, y;
    int w, s;
    cin >> x >> y >> w >> s;

    long long time = 0;
    long long cross = min(x, y);
    long long length = max(x, y) - cross;
    if (w * 2 > s)
        time += s * cross;
    else
        time += w * 2 * cross;

    long long halfLength = length / 2;
    if (w > s)
        time += s * 2 * halfLength;
    else
        time += w * 2 * halfLength;

    time += w * (length % 2);
    cout << time;
}