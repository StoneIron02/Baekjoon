#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 1LL * n * i + i;
    }
    cout << sum;
}