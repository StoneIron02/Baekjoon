#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    int n;
    cin >> a >> b >> n;

    int r = a % b * 10;
    for (int i = 1; i < n; i++)
        r = r % b * 10;
    cout << (r / b);
}