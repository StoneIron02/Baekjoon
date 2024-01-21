#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    if (a.size() < b.size()) {
        string tmp = a;
        a = b;
        b = tmp;
    }
    int g = gcd(a.size(), b.size());
    int l = a.size() * b.size() / g;
    string aLong = a, bLong = b;
    while (aLong.size() != l) {
        aLong += a;
    }
    while (bLong.size() != l) {
        bLong += b;
    }
    cout << (aLong == bLong);
}