#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    cout << (n * (n - 1) * (n - 2) / 6) << "\n";
    cout << 3;
}