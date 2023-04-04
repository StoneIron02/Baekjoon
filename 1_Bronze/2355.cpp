#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long a, b;
    cin >> a >> b;
    if (b > a) {
        long long temp = a;
        a = b;
        b = temp;
    }

    long long sum = ((a + b) * (a - b + 1)) / 2;

    cout << sum;
}