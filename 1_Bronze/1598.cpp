#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int ax = (a - 1) / 4;
    int ay = (a - 1) % 4;
    int bx = (b - 1) / 4;
    int by = (b - 1) % 4;

    int result = abs(ax - bx) + abs(ay - by);
    cout << result;
}