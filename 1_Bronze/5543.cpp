#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    cin >> x >> y;

    int min = 1000000;
    min = (a + x < min) ? a + x : min;
    min = (b + x < min) ? b + x : min;
    min = (c + x < min) ? c + x : min;
    min = (a + y < min) ? a + y : min;
    min = (b + y < min) ? b + y : min;
    min = (c + y < min) ? c + y : min;
    cout << (min - 50);
}