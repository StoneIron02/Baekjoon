#include <iostream>

using namespace std;

long long fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return fact(n - 1) * n;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << fact(n);
}