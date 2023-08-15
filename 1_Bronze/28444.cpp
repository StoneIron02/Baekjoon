#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int h, i, a, r, c;
    cin >> h >> i >> a >> r >> c;
    int var1 = h * i;
    int var2 = a * r * c;
    int result = var1 - var2;
    cout << result;
}