#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int v1 = (a + 1) * (b + 1) - a - b - a * b;
    int v2 = v1 * v1;
    cout << v2;
}