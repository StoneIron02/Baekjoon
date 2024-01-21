#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 2; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int sum = 6 * a + 3 * b + 2 * c + 1 * d + 2 * e;
        cout << sum << " ";
    }
}