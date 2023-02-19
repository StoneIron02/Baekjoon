#include <iostream>

using namespace std;

long long fib[91];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 91; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int n;
    cin >> n;
    cout << fib[n];
}