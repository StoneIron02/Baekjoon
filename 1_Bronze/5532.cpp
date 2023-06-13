#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;

    int koreanDay = a / c;
    if (a % c != 0)
        koreanDay++;
    int mathDay = b / d;
    if (b % d != 0)
        mathDay++;
    int maxDay = max(koreanDay, mathDay);
    cout << (l - maxDay);
}