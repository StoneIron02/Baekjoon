#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 5;
        exit(0);
    }
    if (n == 2) {
        cout << 12;
        exit(0);
    }
    int i = 2;
    long long sum = 12;
    int factor = 10;
    while (i < n) {
        sum = (sum + factor) % 45678;
        factor = (factor + 3) % 45678;
        i++;
    }
    cout << sum;
}