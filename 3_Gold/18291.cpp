#include <iostream>

using namespace std;

int HASH = 1e9 + 7;

int power(int n) {
    if (n == 0) {
        return 1;
    }

    long long p = power(n / 2);
    if (n % 2 == 0) {
        return p * p % HASH;
    }
    else {
        return p * p % HASH * 2 % HASH;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << "\n";
        } else {
            cout << power(n - 2) << "\n";
        }
    }
}