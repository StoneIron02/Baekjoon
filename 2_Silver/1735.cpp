#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int m = b * d / gcd(b, d);
    int n = (m / b) * a + (m / d) * c;
    int co = gcd(m, n);
    m /= co;
    n /= co;
    cout << n << " " << m;
}