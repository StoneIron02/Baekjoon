#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        int temp = b;
        b = a;
        a = temp;
    }

    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    long long lcm = (long long)a * b / gcd(a, b);
    cout << lcm;
}